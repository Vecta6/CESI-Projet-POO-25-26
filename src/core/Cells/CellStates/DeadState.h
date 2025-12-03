//
// Created by nathan on 02/12/2025.
//
#pragma once
#ifndef CESI_PROJECT_POO_25_26_DEADSTATE_H
#define CESI_PROJECT_POO_25_26_DEADSTATE_H

#include "../CellState.h"

class DeadState:CellState{
public:
    bool isAlive() override;
    char symbol() override;
};

#endif //CESI_PROJECT_POO_25_26_DEADSTATE_H