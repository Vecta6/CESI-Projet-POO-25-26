#pragma once

#include "../CellState.h"

class AliveState:public CellState{
public:
    bool isAlive() override {return true;}
    char symbol() override {return '■';}
};