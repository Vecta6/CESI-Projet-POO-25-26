#pragma once
#include "CellState.h"

class Cell {
    private:
        CellState* state;
    public:
        Cell();
        Cell(int state);

        //setters
        void setState(CellState* newState);

        //methods (Deja def dans differentes State ! vraiment necessaire ici ??)
        bool isAlive();
        char symbol();
};