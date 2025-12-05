#pragma once

#include "../CellState.h"

class AliveState:public CellState{
public:
    bool isAlive() override;
    int value() override;
    bool canBeModified() override;
};
