#include "Console.h"

#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

Console::Console(const std::string &filePath, int steps)
    : inputFile(filePath),
      maxIterations(steps > 0 ? steps : 0) {
    const std::string baseName = inputFile.stem().empty() ? "grille" : inputFile.stem().string();
    outputDirectory = inputFile.parent_path() / (baseName + "_out");
    std::filesystem::create_directories(outputDirectory);

    initializeFromFile();
}

Console::Console(const std::string &filePath) : Console(filePath, 10) {}

void Console::initializeFromFile() {
    const std::string fileContent = GestionFichier::LireFichier(inputFile.string());
    int rows = 0;
    int cols = 0;
    const auto gridData = GridSerializer::load(fileContent, rows, cols);

    if (rows == 0 || cols == 0 || gridData.empty()) {
        throw std::runtime_error("Fichier d'entree invalide ou vide: " + inputFile.string());
    }

    game = std::make_unique<Game>(gridData);
}

std::vector<std::vector<int>> Console::captureGridState() const {
    Grid *grid = game->getGrid();
    const int rows = grid->getLines();
    const int cols = grid->getColumns();

    std::vector<std::vector<int>> state(rows, std::vector<int>(cols, 0));
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            state[r][c] = grid->getCell(r, c).getState()->value();
        }
    }

    return state;
}

void Console::writeStateToFile(const std::vector<std::vector<int>> &state, int iteration) const {
    int rows = 0;
    int cols = 0;
    const std::string serialized = GridSerializer::dump(state, rows, cols);
    const auto target = outputDirectory / ("iteration_" + std::to_string(iteration) + ".txt");

    if (!GestionFichier::EcrireFichier(target.string(), serialized)) {
        std::cerr << "Echec de l'ecriture du fichier: " << target << std::endl;
    }
}

void Console::run() {
    auto currentState = captureGridState();
    writeStateToFile(currentState, 0);

    for (int i = 1; i <= maxIterations; i++) {
        game->step();
        auto nextState = captureGridState();
        writeStateToFile(nextState, i);

        if (nextState == currentState) {
            std::cout << "Stabilisation atteinte a l'iteration " << i << ".\n";
            break;
        }

        currentState = std::move(nextState);
    }
}

void Console::showCurrentGrid() {
    const auto state = captureGridState();
    for (const auto &row : state) {
        for (std::size_t c = 0; c < row.size(); c++) {
            if (c > 0) std::cout << ' ';
            std::cout << row[c];
        }
        std::cout << '\n';
    }
}
