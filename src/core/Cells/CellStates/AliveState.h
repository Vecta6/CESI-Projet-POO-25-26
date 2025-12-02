//
// Created by nathan on 02/12/2025.
//
#pragma once
#ifndef CESI_PROJECT_POO_25_26_ALIVESTATE_H
#define CESI_PROJECT_POO_25_26_ALIVESTATE_H



#include "../CellState.h"

class AliveState:CellState{
public:
    bool isAlive();
    char symbol();
};


#endif //CESI_PROJECT_POO_25_26_ALIVESTATE_H