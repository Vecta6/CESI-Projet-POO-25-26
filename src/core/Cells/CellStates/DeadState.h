#pragma once

#include "../CellState.h"

class DeadState:public CellState{
public:
    bool isAlive() override {return false;}
    char symbol() override {return '⋅';}
};