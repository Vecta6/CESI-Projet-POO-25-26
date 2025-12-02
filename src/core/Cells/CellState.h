//
// Created by nathan on 02/12/2025.
//
#pragma once
#ifndef CESI_PROJECT_POO_25_26_CELLSTATE_H
#define CESI_PROJECT_POO_25_26_CELLSTATE_H




class CellState{
public:
    CellState();
    virtual ~CellState() = 0;
    virtual bool isAlive() = 0;
    virtual char symbol() = 0;
};

#endif //CESI_PROJECT_POO_25_26_CELLSTATE_H