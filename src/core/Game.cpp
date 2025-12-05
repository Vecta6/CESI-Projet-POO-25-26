#include "Game.h"
#include "Rule/Rules/ClassicLifeRule.h"
#include <memory>

Game::Game(const std::vector<std::vector<int>> &gridData){
     grid = std::make_unique<Grid>(gridData);
     rule = std::make_unique<ClassicLifeRule>();
}

Game::~Game() = default;

Grid* Game::getGrid(){return grid.get();}

void Game::run(int stepNumber){
    for (int i = 0; i < stepNumber; i++){
        step();
    }
}

void Game::step(){grid->step(rule.get());}
