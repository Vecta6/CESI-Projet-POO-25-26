#include "Rule.h"

class ClassicLifeRule:Rule{
    public:
        CellState* computeNextState(Cell cell, int aliveNeighbours);
};