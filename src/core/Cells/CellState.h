#pragma once

class CellState{
public:
    CellState() = default;
    virtual ~CellState() = default;
    virtual bool isAlive() = 0;
    virtual char symbol() = 0;
};
