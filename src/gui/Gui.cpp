#include "Gui.h"

#include <SFML/Window/Event.hpp>
#include <algorithm>
#include <iostream>
#include <sstream>

Gui::Gui(const std::string &filePath)
    : filePath(filePath),
      game(nullptr),
      window(nullptr),
      Lines(0),
      Columns(0),
      cellSize(20),
      iterationDelay(0.5f),
      paused(false) {
    std::string initBoard = GestionFichier::LireFichier(filePath);
    game = std::make_unique<Game>(GridSerializer::load(initBoard, Lines, Columns));

    // Dimensions de la fenêtre
    const int hudHeight = 180;  // espace suffisant pour le texte
    const int minWidth = 480;
    const int minHeight = 360;

    Grid *grid = game->getGrid();
    const int gridWidth = grid->getColumns() * cellSize;
    const int gridHeight = grid->getLines() * cellSize;

    const int windowWidth = std::max(gridWidth, minWidth);
    const int windowHeight = std::max(gridHeight + hudHeight, minHeight);

    window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(static_cast<unsigned int>(windowWidth),
                      static_cast<unsigned int>(windowHeight)),
        "Jeu de la Vie");
    window->setFramerateLimit(60);

    // Cherche une police "basique" courante sur Linux/Windows/macOS pour éviter les erreurs.
    const std::string candidates[] = {
        "/usr/share/fonts/TTF/DejaVuSans.ttf",                        // Arch/Manjaro
        "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf",            // Debian/Ubuntu
        "/usr/share/fonts/dejavu/DejaVuSans.ttf",                     // Générique
        "/usr/share/fonts/truetype/noto/NotoSans-Regular.ttf",        // Noto
        "/usr/share/fonts/truetype/ubuntu/Ubuntu-R.ttf",              // Ubuntu
        "/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf",  // Fedora/RedHat
        "/usr/share/fonts/truetype/freefont/FreeSans.ttf",            // FreeSans
        "/System/Library/Fonts/Supplemental/Arial.ttf",               // macOS
        "/Library/Fonts/Arial.ttf",                                   // macOS (fallback)
        "C:/Windows/Fonts/arial.ttf"                                  // Windows
    };

    bool fontLoaded = false;
    for (const auto &candidate : candidates) {
        if (font.loadFromFile(candidate)) {
            fontLoaded = true;
            break;
        }
    }
    if (!fontLoaded) {
        std::cout << "Erreur : aucune police systeme standard n'a pu etre chargee.\n";
    }

    const float hudTop = static_cast<float>(gridHeight) + 10.f;
    statusText.setFont(font);
    statusText.setCharacterSize(20);
    statusText.setString("PLAY");
    statusText.setFillColor(sf::Color::Green);
    statusText.setPosition(sf::Vector2f(10.f, hudTop));

    speedText.setFont(font);
    speedText.setCharacterSize(18);
    speedText.setString("Vitesse: 0.5s");
    speedText.setFillColor(sf::Color::Black);
    speedText.setPosition(sf::Vector2f(10.f, hudTop + 28.f));

    helpText.setFont(font);
    helpText.setCharacterSize(14);
    helpText.setString("Espace: Pause/Play\nHaut/Bas: Vitesse\nDroite: Pas a pas (en pause)\nR: Reset");
    helpText.setFillColor(sf::Color(80, 80, 80));
    helpText.setPosition(sf::Vector2f(10.f, hudTop + 56.f));
}

Gui::~Gui() = default;

void Gui::render() {
    window->clear(sf::Color::White);

    Grid *grid = game->getGrid();
    const int gridHeight = grid->getLines() * cellSize;

    // Draw each cell
    for (int i = 0; i < grid->getLines(); i++) {
        for (int j = 0; j < grid->getColumns(); j++) {
            Cell &cell = grid->getCell(i, j);

            sf::RectangleShape rectangle(sf::Vector2f(static_cast<float>(cellSize - 1),
                                                      static_cast<float>(cellSize - 1)));
            rectangle.setPosition(
                sf::Vector2f(static_cast<float>(j * cellSize), static_cast<float>(i * cellSize)));

            if (cell.getState()->value() == 1) {
                rectangle.setFillColor(sf::Color::Black);
            } else if (cell.getState()->value() == 0) {
                rectangle.setFillColor(sf::Color::White);
            } else if (cell.getState()->value() == 2) {
                rectangle.setFillColor(sf::Color(128, 128, 128));
            } else if (cell.getState()->value() == 3) {
                rectangle.setFillColor(sf::Color(144, 238, 144));
            }

            window->draw(rectangle);
        }
    }

    // Bandeau HUD pour lisibilité
    const float hudStart = static_cast<float>(gridHeight);
    sf::RectangleShape hudBg(
        sf::Vector2f(static_cast<float>(window->getSize().x), window->getSize().y - hudStart));
    hudBg.setPosition(sf::Vector2f(0.f, hudStart));
    hudBg.setFillColor(sf::Color(245, 245, 245));
    window->draw(hudBg);

    window->draw(statusText);
    window->draw(speedText);
    window->draw(helpText);
    window->display();
}

void Gui::handleEvents() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }

        if (event.type == sf::Event::KeyPressed) {
            const auto code = event.key.code;
            if (code == sf::Keyboard::Up) {
                iterationDelay -= 0.1f;
                if (iterationDelay < 0.1f) iterationDelay = 0.1f;
                std::ostringstream oss;
                oss << "Vitesse: " << iterationDelay << "s";
                speedText.setString(oss.str());

            } else if (code == sf::Keyboard::Down) {
                iterationDelay += 0.1f;
                std::ostringstream oss;
                oss << "Vitesse: " << iterationDelay << "s";
                speedText.setString(oss.str());

            } else if (code == sf::Keyboard::Space) {
                paused = !paused;
                statusText.setString(paused ? "PAUSE" : "PLAY");
                statusText.setFillColor(paused ? sf::Color::Red : sf::Color::Green);
            } else if (code == sf::Keyboard::Right) {
                if (paused) {
                    game->step();
                }
            } else if (code == sf::Keyboard::R) {
                reset();
                paused = true;
                statusText.setString("PAUSE");
                statusText.setFillColor(sf::Color::Red);
            }
        }
    }
}

void Gui::reset() {
    std::string initBoard = GestionFichier::LireFichier(filePath);
    game = std::make_unique<Game>(GridSerializer::load(initBoard, Lines, Columns));
}

void Gui::update() {
    if (!paused && clock.getElapsedTime().asSeconds() >= iterationDelay) {
        game->step();
        clock.restart();
    }
}

void Gui::run() {
    while (window->isOpen()) {
        handleEvents();
        update();
        render();
    }
}
