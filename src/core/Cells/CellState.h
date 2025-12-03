#pragma once

class CellState{
public:
    CellState();
    virtual ~CellState(){}
    virtual bool isAlive() = 0;
    virtual char symbol() = 0;
};

class AliveState:public CellState{
public:
    bool isAlive() override {return true;}
    char symbol() override {return '■';}
};

class DeadState:public CellState{
    public:
        bool isAlive() override {return false;}
        char symbol() override {return '⋅';}
};