//
// Created by nathan on 02/12/2025.
//

#pragma once
#ifndef CESI_PROJECT_POO_25_26_GRID_H
#define CESI_PROJECT_POO_25_26_GRID_H

#include "core/Cells/Cell.h"
#include "core/Rule/Rule.h"
#include <vector>

class Grid{
private:
    int width;
    int height;
    std::vector<std::vector<int>> grid;
public:
    Grid(int width, int height, std::vector<std::vector<int>>& grid);

    //getters
    Cell& getCell(int x, int y);

    //methods
    int countAliveNeighbours(int x, int y);
    void step(Rule* rule);
};


#endif //CESI_PROJECT_POO_25_26_GRID_H