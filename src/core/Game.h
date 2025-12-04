#pragma once
#include "../console/Console.h"
#include "../core/Grid.h"
#include "../core/Rule/Rules/ClassicLifeRule.h"

#include <vector>
using namespace std;

class Game{
    private:
        Grid* grid;
        Rule* rule;
    public:
        Game(int width, int height, vector<vector<int>>& grid); 
        ~Game();

        //getters
        Grid* getGrid();

        //methods
        void run(int stepNumber);
        void step();
};