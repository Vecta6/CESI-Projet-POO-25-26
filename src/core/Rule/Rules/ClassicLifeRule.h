#pragma once

#include "../Rule.h"
#include "../../Cells/CellState.h"
#include "../../Cells/Cell.h"

class ClassicLifeRule:public Rule{
public:
    CellState* computeNextState(Cell* cell, int aliveNeighbours) override;
};