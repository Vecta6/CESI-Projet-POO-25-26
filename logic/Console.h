#pragma once
#include "Game.h"
#include <iostream>
using namespace std;

class Console{
    protected:
        Game game;
    public:
        Console(string filePath, int steps);
        Console(string filePath);

        virtual void showCurrentGrid();
};