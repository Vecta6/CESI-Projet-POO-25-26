#pragma once
#include "Grid.h"
#include <fstream>
#include <iostream>
using namespace std;

Grid::Grid(string filePath){
    string line;
    while(getline(filePath, line)){
        
    }
}

Cell& Grid::getCell(int x, int y){

}

int Grid::countAliveNeighbours(int x, int y){

}

void Grid::step(Rule* rule){

}