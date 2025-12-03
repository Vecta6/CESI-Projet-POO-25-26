#include "Game.h"
#include "Rule/Rules/ClassicLifeRule.h"

Game::Game(int width, int height, vector<vector<int>>& grid){
     rule = new ClassicLifeRule();
}

/*#include <iostream>
Game::Game(string filePath) {
    grid = new Grid(filePath);
    rule = new ClassicLifeRule();
}*/

Game::~Game(){
    delete grid;
    delete rule;
}

Grid* Game::getGrid(){return grid;}

void Game::run(int stepNumber){
    for (int i = 0; i < stepNumber; i++){
        step();
    }
}

void Game::step(){grid->step(rule);}