#include "Cell.h"
#include "CellStates/AliveState.h"
#include "CellStates/DeadState.h"

Cell::Cell(int initial) : state(nullptr) {

    if (initial != 0) {
        state = new AliveState;
    } else {
        state = new DeadState;
    }
}

void Cell::setState(CellState* newState) {
    delete state;
    state = newState;
}

CellState* Cell::getState() const {
    return state;
}
