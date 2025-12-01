#include "../Rule.h"
#include "../../Cells/CellState.h"
#include "../../Cells/Cell.h"

class ClassicLifeRule:Rule{
    public:
        CellState* computeNextState(Cell cell, int aliveNeighbours);
};