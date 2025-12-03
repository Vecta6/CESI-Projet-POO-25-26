#pragma once

class CellState{
public:
    CellState();
    virtual ~CellState(){}
    virtual bool isAlive() = 0;
    virtual char symbol() = 0;
};
