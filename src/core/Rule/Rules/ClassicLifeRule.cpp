#include "ClassicLifeRule.h"
#include "../../Cells/CellStates/AliveState.h"
#include "../../Cells/CellStates/DeadState.h"
#include "../../Cells/CellState.h"

CellState* ClassicLifeRule::computeNextState(const Cell& cell, int aliveNeighbours) {
    if (cell.getState()->isAlive()) {
        if (aliveNeighbours == 2 || aliveNeighbours == 3) {
            return new AliveState;
        } else {
            return new DeadState;
        }
    }

    if (aliveNeighbours == 3) {
        return new AliveState;
    } else {
        return new DeadState;
    }
}
