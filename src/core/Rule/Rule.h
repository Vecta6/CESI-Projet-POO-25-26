//
// Created by nathan on 02/12/2025.
//

#pragma once
#ifndef CESI_PROJECT_POO_25_26_RULE_H
#define CESI_PROJECT_POO_25_26_RULE_H

<<<<<<< HEAD


#include "../Cells/CellState.h"
#include "../Cells/Cell.h"
=======
class Cell;
class CellState;
>>>>>>> be0fac0889aeafe0555e5fba1ae29c1a654ac777

class Rule {
public:
    virtual CellState* computeNextState(const Cell& cell, int aliveNeighbours) = 0;
    virtual ~Rule() = 0;
};


#endif //CESI_PROJECT_POO_25_26_RULE_H
