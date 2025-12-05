#pragma once

#include "../core/Game.h"
#include "../GestionFichiers.h"
#include "../utils/GridSerializer.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>    
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Gui {
    private:
    string FilePath;
    Game* game;
    RenderWindow* window;
    int Lines;
    int Columns;
    int cellSize;          //pixels
    float iterationDelay;  //seconds
    Clock clock;
    bool paused;
    Font font;       
    Text statusText;
    Text speedText;
    Text helpText;

    public:
        Gui(string filePath);
        ~Gui();

        //methods
        void render();
        void handleEvents();
        void reset();
        void update();
        void run();
};