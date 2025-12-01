#pragma once
#include "../CellState.h"

class DeadState:CellState{
    public:
        bool isAlive();
        char symbol();
};