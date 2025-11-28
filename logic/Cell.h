#pragma once
#include "CellState.h"

class Cell {
    private:
        CellState* state;
    public:
        Cell();
        Cell(int state);

        //setters
        void setState(CellState* newState);
};