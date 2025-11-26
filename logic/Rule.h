#pragma once
#include "CellState.h"
#include "Grid.h"
#include "Cell.h"

class Rule{
    public:
        virtual CellState* computeNextState(Cell cell, int aliveNeighbours) = 0;
};
