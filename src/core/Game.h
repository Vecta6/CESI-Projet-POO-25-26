#pragma once
#include "../core/Grid.h"
#include "../core/Rule/Rules/ClassicLifeRule.h"
#include <memory>
#include <vector>

class Game{
    private:
        std::unique_ptr<Grid> grid;
        std::unique_ptr<Rule> rule;
    public:
        explicit Game(const std::vector<std::vector<int>> &gridData);
        ~Game();

        //getters
        Grid* getGrid();

        //methods
        void run(int stepNumber);
        void step();
};
