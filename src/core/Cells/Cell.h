#pragma once
#include "CellState.h"

class Cell {
private:
    CellState* state;
public:
    Cell() : state(nullptr) {}
    explicit Cell(int state);
    explicit Cell(CellState* initialState) : state(initialState) {}
    ~Cell() { delete state; }

    Cell(const Cell&) = delete;
    Cell& operator=(const Cell&) = delete;
    Cell(Cell&&) = delete;
    Cell& operator=(Cell&&) = delete;

    void setState(CellState* newState);
    CellState* getState() const;
};
