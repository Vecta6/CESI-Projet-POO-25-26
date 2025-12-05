#include "Cell.h"
#include "CellStates/AliveState.h"
#include "CellStates/DeadState.h"
#include "CellStates/ObstacleAlive.h"
#include "CellStates/ObstacleDead.h"
#include <memory>

Cell::Cell(int initial) : state(nullptr) {
    switch (initial) {
        case 1:
            state = std::make_unique<AliveState>();
            break;
        case 2:
            state = std::make_unique<ObstacleDead>();
            break;
        case 3:
            state = std::make_unique<ObstacleAlive>();
            break;
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
