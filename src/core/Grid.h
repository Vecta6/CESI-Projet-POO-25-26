#pragma once

#include <vector>

#include "Cells/Cell.h"

class Rule;

class Grid {
private:
    int columns;
    int lines;
    std::vector<std::vector<Cell>> cells;

public:
    // Build a grid from an integer matrix (values map to cell states).
    explicit Grid(const std::vector<std::vector<int>> &initialState);
    ~Grid() = default;

    // Accessors
    Cell &getCell(int line, int column);
    int getLines() const { return lines; }
    int getColumns() const { return columns; }
    
    // Simulation helpers
    int countAliveNeighbours(int line, int column) const;
    void step(Rule* rule);
};
