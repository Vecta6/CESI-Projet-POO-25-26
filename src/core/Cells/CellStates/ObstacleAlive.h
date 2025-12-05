#pragma once

#include "../CellState.h"

class ObstacleAlive:public CellState{
public:
    bool isAlive() override;
    int value() override;
    bool canBeModified() override;
};
