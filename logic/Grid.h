#pragma once
#include "Cell.h"
#include "Rule.h"
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