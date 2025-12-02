#pragma once
#include "Cell.h"
#include "Rule.h"
#include <vector>
#include <iostream>
using namespace std;

class Grid{
    private:
        int width;
        int height;
    public:
        Grid(string filePath);

        //getters
        Cell& getCell(int x, int y);
        
        //methods
        int countAliveNeighbours(int x, int y);
        void step(Rule* rule);
};