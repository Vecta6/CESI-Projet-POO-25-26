#include "Grid.h"
#include "Cells/CellState.h"
#include "Rule/Rule.h"
#include <vector>
#include <memory>

Grid::Grid(const std::vector<std::vector<int>> &initialState) {
    lines = static_cast<int>(initialState.size());
    columns = lines > 0 ? static_cast<int>(initialState[0].size()) : 0;

    cells.resize(lines);
    for (int r = 0; r < lines; r++) {
        cells[r].reserve(columns);
        for (int c = 0; c < columns; c++) {
            int value = initialState[r][c];
            cells[r].emplace_back(value);
        }
    }
}

Cell &Grid::getCell(int line, int column) {
    return cells[line][column];
}

int Grid::countAliveNeighbours(int line, int column) const {
    int count = 0;

    auto wrap = [](int idx, int max) {
        const int mod = idx % max;
        return mod < 0 ? mod + max : mod;
    };

    // Voisinage avec grille torique (bords qui bouclent).
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;

            const int neighbourLine = wrap(line + i, lines);
            const int neighbourColumn = wrap(column + j, columns);

            if (cells[neighbourLine][neighbourColumn].getState()->isAlive()) {
                count++;
            }
        }
    }
    return count;
}

void Grid::step(Rule *rule) {
    // Temporary copy of new states
    std::vector<std::vector<std::unique_ptr<CellState>>> newStates(lines);

    for (int i = 0; i < lines; i++) {
        newStates[i].resize(columns);
    }

    // Calculate new states
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            int aliveNeighbours = countAliveNeighbours(i, j);
            newStates[i][j].reset(rule->computeNextState(cells[i][j], aliveNeighbours));
        }
    }
    
    // Apply new states
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            cells[i][j].setState(std::move(newStates[i][j]));
        }
    }
}
