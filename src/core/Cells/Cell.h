#pragma once
#include "CellState.h"

class Cell {
private:
    CellState* state;
public:
    Cell();
    Cell(int cellValue);
    Cell(CellState* initialState);

    void setState(CellState* newState);

    CellState* getState();
};
