#include "Cell.h"
#include "CellStates/AliveState.h"
#include "CellStates/DeadState.h"
#include <memory>

Cell::Cell(int initial) : state(nullptr) {
    switch (initial) {
        case 1:
            state = std::make_unique<AliveState>();
            break;
        case 0:
        default:
            state = std::make_unique<DeadState>();
            break;
    }
}

void Cell::setState(std::unique_ptr<CellState> newState) {
    state = std::move(newState);
}

CellState* Cell::getState() const {
    return state.get();
}
