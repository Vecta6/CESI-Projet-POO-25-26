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
    explicit Grid(const std::vector<std::vector<int>> &initialState);
    ~Grid() = default;

    // Getters
    Cell &getCell(int line, int column);
    int getLines() const { return lines; }
    int getColumns() const { return columns; }
    
    // Methods
    int countAliveNeighbours(int line, int column) const;
    void step(Rule* rule);
};
