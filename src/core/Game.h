#pragma once
#include "Console.h"
#include "Grid.h"
#include "Rule.h"

#include <vector>
using namespace std;

class Game{
    private:
        Grid grid;
        Rule* rule;
    public:
        Game(int width, int height, vector<vector<int>>& grid); 
        //getters
        Grid getGrid();

        //methods
        void run(int stepNumber);
        void step();
};