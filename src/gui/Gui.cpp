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
      paused(false),
      statusText(font, "PLAY", 20),       // emoji retirés pour éviter les symboles manquants
      speedText(font, "Vitesse: 0.5s", 18),
      helpText(font,
               "Espace: Pause/Play\n"
               "Haut/Bas: Vitesse\n"
               "Droite: Pas a pas (en pause)\n"
               "R: Reset",
               14) {
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
        sf::VideoMode(sf::Vector2u(static_cast<unsigned int>(windowWidth),
                                   static_cast<unsigned int>(windowHeight))),
        "Jeu de la Vie");
    window->setFramerateLimit(60);

    // Essai multi-chemins pour compat Arch/Debian/Ubuntu.
    const std::string candidates[] = {
        "/usr/share/fonts/TTF/DejaVuSans.ttf",                  // Arch/Manjaro
        "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf",      // Debian/Ubuntu
        "/usr/share/fonts/dejavu/DejaVuSans.ttf"                // Générique
    };
    bool fontLoaded = false;
    for (const auto &candidate : candidates) {
        if (font.openFromFile(candidate)) {
            fontLoaded = true;
            break;
        }
    }
    if (!fontLoaded) {
        std::cout << "Erreur : impossible de charger la police (DejaVuSans)\n";
    }

    const float hudTop = static_cast<float>(gridHeight) + 10.f;
    statusText.setFillColor(sf::Color::Green);
    statusText.setPosition(sf::Vector2f(10.f, hudTop));

    speedText.setFillColor(sf::Color::Black);
    speedText.setPosition(sf::Vector2f(10.f, hudTop + 28.f));

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
    while (auto eventOpt = window->pollEvent()) {
        const auto &event = *eventOpt;

        if (event.is<sf::Event::Closed>()) {
            window->close();
        }

        if (const auto *key = event.getIf<sf::Event::KeyPressed>()) {
            const auto code = key->code;
            if (code == sf::Keyboard::Key::Up) {
                iterationDelay -= 0.1f;
                if (iterationDelay < 0.1f) iterationDelay = 0.1f;
                std::ostringstream oss;
                oss << "Vitesse: " << iterationDelay << "s";
                speedText.setString(oss.str());

            } else if (code == sf::Keyboard::Key::Down) {
                iterationDelay += 0.1f;
                std::ostringstream oss;
                oss << "Vitesse: " << iterationDelay << "s";
                speedText.setString(oss.str());

            } else if (code == sf::Keyboard::Key::Space) {
                paused = !paused;
                statusText.setString(paused ? "PAUSE" : "PLAY");
                statusText.setFillColor(paused ? sf::Color::Red : sf::Color::Green);
            } else if (code == sf::Keyboard::Key::Right) {
                if (paused) {
                    game->step();
                }
            } else if (code == sf::Keyboard::Key::R) {
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
