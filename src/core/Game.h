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
        // Build a game with the given initial grid and the classic Conway rule.
        explicit Game(const std::vector<std::vector<int>> &gridData);
        ~Game();

        // Accessors
        Grid* getGrid();

        // Simulation control
        // Run a fixed number of iterations.
        void run(int stepNumber);
        // Run a single iteration.
        void step();
};
