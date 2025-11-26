#pragma once
#include "CellState.h"

class AliveState:CellState{
    public:
        bool isAlive();
        char symbol();
};