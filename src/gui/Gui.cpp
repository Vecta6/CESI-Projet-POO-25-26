#include "Gui.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>



Gui::Gui(string filePath, int cellSize){
    this->cellSize = cellSize;
    this->iterationDelay = 0.5f;       //default => 0.5 seconds
    this->paused = false;

    //Create a new game
    game = new Game();  //mettre à jour selon nouveau constructeur

    //Window size
    Grid* grid = game->getGrid();
    int windowWidth = grid->getColumns() * cellSize;
    int windowHeight = grid->getLines() * cellSize;

    //Create the window
    window = new RenderWindow(VideoMode(windowWidth, windowHeight),"Jeu de la Vie");
    window->setFramerateLimit(60);

    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        cout << "Erreur : impossible de charger la police" << endl;
    }
    
    //Text
    statusText.setFont(font);
    statusText.setCharacterSize(20);
    statusText.setFillColor(Color::Green);
    statusText.setPosition(10, 10);
    statusText.setString("▶ PLAY");
}

Gui::~Gui() {
    delete game;
    delete window;
}

void Gui::render() {
    window->clear(Color::White);
    
    Grid* grid = game->getGrid();

    //Draw each cell
    for (int i = 0; i < grid->getLines(); i++) {
        for (int j = 0; j < grid->getColumns(); j++) {
            Cell& cell = grid->getCell(i, j);
            
            //Rectangle for the cell
            RectangleShape rectangle(Vector2f(cellSize - 1, cellSize - 1));
            rectangle.setPosition(j * cellSize, i * cellSize);
            
            //Color of the cell
            if (cell.getState()->value() == 1) {        //Alive cell
                rectangle.setFillColor(Color::Black);
            } 
            else if (cell.getState()->value() == 0) { //Dead cell
                rectangle.setFillColor(Color::White);
            }
            
            window->draw(rectangle);
        }
    }
    window->draw(statusText);   //Draw text
    window->display();  //End the current frame and display its contents on screen
}

void Gui::handleEvents() {
    Event event;
    while (window->pollEvent(event)) {
        if (event.type == Event::Closed) {
            window->close();
        }
        
        //Iteration speed control
        if (event.type == Event::KeyPressed) {
            if (event.key.code == Keyboard::Up) {
                iterationDelay -= 0.1f;
                if (iterationDelay < 0.1f) iterationDelay = 0.1f;
                
            }
            else if (event.key.code == Keyboard::Down) {
                iterationDelay += 0.1f;
                
            }
            else if (event.key.code == Keyboard::Space) {
                //Pause/Play
                paused = !paused;  // ← Inverse l'état
                if (paused) {
                    statusText.setString("⏸ PAUSE");
                    statusText.setFillColor(Color::Red);
                } else {
                    statusText.setString("▶ PLAY");
                    statusText.setFillColor(Color::Green);
                }
            }
        }
    }
}