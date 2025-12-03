#pragma once
#include "Grid.h"
#include "Cells/CellState.h"
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