//
// Created by nathan on 02/12/2025.
//

#pragma once
#ifndef CESI_PROJECT_POO_25_26_CLASSICLIFERULE_H
#define CESI_PROJECT_POO_25_26_CLASSICLIFERULE_H


#include "../Rule.h"
#include "../../Cells/CellState.h"
#include "../../Cells/Cell.h"

class ClassicLifeRule:Rule{
public:
    CellState* computeNextState(Cell cell, int aliveNeighbours) override;
};

#endif //CESI_PROJECT_POO_25_26_CLASSICLIFERULE_H