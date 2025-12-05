#pragma once

#include "../CellState.h"

class ObstacleAlive:public CellState{
public:
    bool isAlive() override;
    char32_t symbol() override;
    int value() override;
    bool canBeModified() override;
};