#pragma once

#include "../CellState.h"

class ObstacleDead:public CellState{
public:
    bool isAlive() override;
    int value() override;
    bool canBeModified() override;
};
