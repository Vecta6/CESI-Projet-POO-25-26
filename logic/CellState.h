#pragma once

class CellState{
    public:
        virtual bool isAlive() = 0;
        virtual char symbol() = 0;
};