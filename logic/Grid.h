#pragma once
#include "Cell.h"
#include "Rule.h"
#include <vector>
#include <iostream>
using namespace std;

class Grid{
    private:
        int columns;
        int lines;
        vector<vector<Cell*>> cells;
    public:
        Grid(string filePath);
        ~Grid();

        //getters
        Cell& getCell(int line, int column);
        int getLines() const { return lines; }
        int getColumns() const { return columns; }
        
        //methods
        int countAliveNeighbours(int line, int column);
        void step(Rule* rule);
};