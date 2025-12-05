#pragma once

#include "CellState.h"
#include <memory>

class Cell {
private:
    std::unique_ptr<CellState> state;
public:
    Cell() = default;
    // Build a cell from an integer value (0 dead, 1 alive, 2 obstacle dead, 3 obstacle alive).
    explicit Cell(int state);
    ~Cell() = default;

    Cell(const Cell&) = delete;
    Cell& operator=(const Cell&) = delete;
    Cell(Cell&& other) noexcept = default;
    Cell& operator=(Cell&& other) noexcept = default;

    void setState(std::unique_ptr<CellState> newState);
    CellState* getState() const;
};
