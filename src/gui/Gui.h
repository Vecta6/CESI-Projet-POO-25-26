#pragma once

#include "../core/Game.h"
#include "../core/GestionFichiers.h"
#include "../core/utils/GridSerializer.h"

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

class Gui {
private:
    std::string filePath;
    std::unique_ptr<Game> game;
    std::unique_ptr<sf::RenderWindow> window;
    int Lines;
    int Columns;
    int cellSize;          // cell size in pixels
    float iterationDelay;  // delay between updates in seconds
    sf::Clock clock;
    bool paused;
    sf::Font font;
    sf::Text statusText;
    sf::Text speedText;
    sf::Text helpText;

public:
    // Initialize the GUI with a board file path.
    explicit Gui(const std::string &filePath);
    ~Gui();

    void render();
    void handleEvents();
    void reset();
    void update();
    void run();
};
