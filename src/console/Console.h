#pragma once

#include <filesystem>
#include <memory>
#include <string>
#include <vector>

#include "../core/Game.h"
#include "../core/GestionFichiers.h"
#include "../core/utils/GridSerializer.h"

class Console {
private:
    std::filesystem::path inputFile;
    std::filesystem::path outputDirectory;
    int maxIterations;
    std::unique_ptr<Game> game;

    void initializeFromFile();
    std::vector<std::vector<int>> captureGridState() const;
    void writeStateToFile(const std::vector<std::vector<int>> &state, int iteration) const;

public:
    Console(const std::string &filePath, int steps);
    explicit Console(const std::string &filePath);

    void run();
    void showCurrentGrid();
};
