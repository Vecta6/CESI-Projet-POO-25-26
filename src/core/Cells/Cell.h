#pragma once

#include "CellState.h"
#include <memory>

class Cell {
private:
    std::unique_ptr<CellState> state;
public:
    Cell() = default;
    explicit Cell(int state);
    explicit Cell(CellState* initialState) : state(initialState) {}
    ~Cell() = default;

    Cell(const Cell&) = delete;
    Cell& operator=(const Cell&) = delete;
    Cell(Cell&& other) noexcept = default;
    Cell& operator=(Cell&& other) noexcept = default;

    void setState(std::unique_ptr<CellState> newState);
    CellState* getState() const;
};
