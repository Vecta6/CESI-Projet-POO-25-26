#pragma once

class CellState{
public:
    CellState() = default;
    virtual ~CellState() = default;
    virtual bool isAlive() = 0;
    virtual int value() = 0;
    virtual bool canBeModified() = 0;
};
