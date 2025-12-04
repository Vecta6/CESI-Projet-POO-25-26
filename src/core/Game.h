#pragma once
#include "../console/Console.h"
#include "../core/Grid.h"
#include "../core/Rule/Rules/ClassicLifeRule.h"

#include <vector>

class Game{
    private:
        Grid grid;
        Rule* rule;
    public:
        Game(int width, int height, std::vector<std::vector<int>>& grid); 
        //getters
        Grid getGrid(){return grid;}

        //methods
        void run(int stepNumber);
        void step();
};