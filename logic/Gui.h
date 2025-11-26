#pragma once
#include "Console.h"
#include <iostream>
using namespace std;

class Gui: public Console {
    private:
        void render();
    public:
        Gui(string filePath):Console(filePath) {}

        void execute();
};