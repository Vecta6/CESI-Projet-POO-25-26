#pragma once
#include "Cell.h"
#include "Rule.h"

class Grid{
    private:
        int width;
        int height;
        int[][] grid;
    public:
        Grid(int width, int height, int[][] grid);

        //getters
        Cell& getCell(int x, int y);
        
        //methods
        int countAliveNeighbours(int x, int y);
        void step(Rule* rule);
};