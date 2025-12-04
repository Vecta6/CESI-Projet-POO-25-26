#pragma once

#include "../CellState.h"

class DeadState:public CellState{
public:
    bool isAlive() override {return false;}
    char32_t symbol() override {return U'⋅';}
    int value() override {return 0;}
    bool canBeModified() override {return true;}
};
