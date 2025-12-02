#pragma once
#include "Grid.h"
#include <fstream>
#include <iostream>
using namespace std;

Grid::Grid(string filePath){
    char character;

    ifstream file(filePath);

    if(!file){
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        lines = 0;
        columns = 0;
        return;
    }

    string line;

    //Read first line to get dimensions
    if (getline(file, line)){
        //Find space position
        int spaceIndex = line.find(' ');
        //Extract + convert lines and columns
        lines = stoi(line.substr(0, spaceIndex));
        columns = stoi(line.substr(spaceIndex + 1));
    }

    //Initialize the grid
    cells.resize(lines);
    for (int i = 0; i < lines; i++){
        cells[i].resize(columns);
    }

    //Read initial state of cells
    int currentLine = 0;
    while (getline(file, line) && currentLine < lines){
        int currentColumn = 0;

        //Run through the line
        for (int i = 0; i < line.size() && currentColumn < columns; i++){
            char character = line[i];

            //Convert the character to 0 or 1
            switch (character)
            {
            case 0:     //Dead cell
                cells[currentLine][currentColumn] = new Cell(new DeadState());
                currentColumn++;
                break;
            
            case 1:     //Alive cell
                cells[currentLine][currentColumn] = new Cell(new AliveState());
                currentColumn++;
                break;
            
            default:
                break;
            }
        }
        currentLine++;
    }
    file.close();
}

Grid::~Grid() {

    for (int i = 0; i < lines; i++){
        for (int j = 0; j < columns; j++){
            delete cells[i][j];
        }
    }
}

Cell& Grid::getCell(int line, int column){
    return *cells[line][column];
}

int Grid::countAliveNeighbours(int line, int column){
    int count = 0;

    //Run through the 8 neighbours
    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
            if (i == 0 && j == 0) continue;

            int neighbourLine = line + i;
            int neighbourColumn = column + j;

            //Check the grid limits
            if (neighbourLine >= 0 && neighbourLine < lines && neighbourColumn >= 0 && neighbourColumn < columns){

                //Increment the counter when a neighbour is alive
                if (cells[neighbourLine][neighbourColumn]->getState()->isAlive()){
                    count++;
                }
            }
        }
    }
    return count;
}

void Grid::step(Rule* rule){
    //Temporary copy of new states
    vector<vector<CellState*>> newStates(lines);

    for (int i = 0; i < lines; i++){
        newStates[i].resize(columns);
    }

    //Calculate new states
    for (int i = 0; i < lines; i++){
        for (int j = 0; j < columns; j++){
            int aliveNeighbours = countAliveNeighbours(i, j);
            newStates[i][j] = rule->computeNextState(cells[i][j], aliveNeighbours);
        }
    }
    
    //Apply new states
    for (int i = 0; i < lines; i++){
        for (int j = 0; j < columns; j++){
            cells[i][j]->setState(newStates[i][j]);
        }
    }
}