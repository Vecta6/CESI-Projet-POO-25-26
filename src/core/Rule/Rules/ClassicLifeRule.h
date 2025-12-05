#pragma once

#include "../Rule.h"
#include "../../Cells/CellState.h"
#include "../../Cells/Cell.h"

class ClassicLifeRule : public Rule {
public:
    // Conway's classic rule: birth on 3, survive on 2 or 3.
    CellState* computeNextState(const Cell& cell, int aliveNeighbours) override;
};
