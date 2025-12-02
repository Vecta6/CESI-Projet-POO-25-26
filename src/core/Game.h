//
// Created by nathan on 02/12/2025.
//

#pragma once
#ifndef CESI_PROJECT_POO_25_26_GAME_H
#define CESI_PROJECT_POO_25_26_GAME_H

#include "../console/Console.h"
#include "Grid.h"
#include "Rule/Rule.h"

#include <vector>

class Game{
private:
    Grid grid;
    Rule* rule;
public:
    Game(int width, int height, std::vector<std::vector<int>>& grid); //verifier creation tableau 2 dim

    //getters
    Grid getGrid(){return grid;}

    //methods
    void run(int stepNumber);
    void step();
};

#endif //CESI_PROJECT_POO_25_26_GAME_H