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
    bool isAlive() override;
    char symbol() override;
};

class DeadState:public CellState{
    public:
        bool isAlive() override;
        char symbol() override;
};