//
// Created by nathan on 02/12/2025.
//
#pragma once
#ifndef CESI_PROJECT_POO_25_26_CELL_H
#define CESI_PROJECT_POO_25_26_CELL_H

#include "CellState.h"

class Cell {
private:
    CellState* state;
public:
    Cell();
    Cell(int state);

    void setState(CellState* newState);
};


#endif //CESI_PROJECT_POO_25_26_CELL_H