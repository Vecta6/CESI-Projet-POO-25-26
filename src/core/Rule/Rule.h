#pragma once
#include "../Cells/CellState.h"
#include "../Cells/Cell.h"
#include "../Grid.h"

class Rule {
    public:
        virtual CellState* computeNextState(Cell cell, int aliveNeighbours) = 0;
};