#pragma once

#include "../CellState.h"

class DeadState:public CellState{
public:
    bool isAlive() override;
    int value() override;
    bool canBeModified() override;
};
