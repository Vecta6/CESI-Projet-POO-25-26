#pragma once
#include "Console.h"
#include "Grid.h"
#include "Rule.h"

class Game{
    private:
        Grid grid;
        Rule* rule;
    public:
        Game(int width, int height, int[][] grid); //verifier creation tableau 2 dim

        //getters
        Grid getGrid(){return grid;}

        //methods
        void run(int stepNumber);
        void step();
};