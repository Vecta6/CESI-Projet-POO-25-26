#pragma once
#ifndef CESI_PROJECT_POO_25_26_RULE_H
#define CESI_PROJECT_POO_25_26_RULE_H

class Cell;
class CellState;

class Rule {
public:
    virtual CellState* computeNextState(const Cell& cell, int aliveNeighbours) = 0;
    virtual ~Rule() = 0;
};


#endif  // CESI_PROJECT_POO_25_26_RULE_H
