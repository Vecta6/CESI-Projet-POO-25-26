#pragma once

#include "../CellState.h"

class AliveState:public CellState{
public:
    bool isAlive() override {return true;}
    char32_t symbol() override {return U'■';}
    int value() override {return 1;}
    bool canBeModified() override {return true;};
};
