#include "Cell.h"
#include "CellState.h"

Cell::Cell(){state = new DeadState();}

Cell::Cell(int cellValue){      //revoir ce constructeur
    switch (cellValue){
        case 0:
            state = new DeadState();
            break;
        
        case 1:
            state = new AliveState();
            break;

        default:
            break;
    }
}

Cell::Cell(CellState* initialState){state = initialState;}

void Cell::setState(CellState* newState){state = newState;}

CellState* Cell::getState(){return state;}