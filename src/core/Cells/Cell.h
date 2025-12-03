#pragma once
#include "CellState.h"

class Cell {
private:
    CellState* state;
public:
    Cell();
    Cell(int state);
    Cell(CellState* initialState){state = initialState;}

    void setState(CellState* newState);
};
