#include <iostream>
#include <string>
#include <vector>

#include "../src/core/Game.h"
#include "../src/core/Grid.h"
#include "../src/core/Rule/Rules/ClassicLifeRule.h"
#include "../src/core/utils/GridSerializer.h"

namespace {

// Helper: compare two grids by value.
bool gridEquals(Grid *grid, const std::vector<std::vector<int>> &expected) {
    if (grid->getLines() != static_cast<int>(expected.size())) return false;
    if (!expected.empty() && grid->getColumns() != static_cast<int>(expected[0].size())) return false;
    for (int r = 0; r < grid->getLines(); ++r) {
        for (int c = 0; c < grid->getColumns(); ++c) {
            if (grid->getCell(r, c).getState()->value() != expected[r][c]) {
                return false;
            }
        }
    }
    return true;
}

bool testGridSerializerLoadAndDump() {
    const std::string content =
        "2 3\n"
        "1 0 2\n"
        "3 1 0\n";
    int rows = 0;
    int cols = 0;
    auto grid = GridSerializer::load(content, rows, cols);
    if (!(rows == 2 && cols == 3)) return false;
    if (!(grid[0][0] == 1 && grid[0][2] == 2)) return false;
    if (!(grid[1][0] == 3 && grid[1][2] == 0)) return false;

    int dumpRows = 0;
    int dumpCols = 0;
    const auto dumped = GridSerializer::dump(grid, dumpRows, dumpCols);
    if (!(dumpRows == 2 && dumpCols == 3)) return false;
    if (dumped.find("2 3") != 0) return false;
    return true;
}

bool testToroidalWrappingStillLifeBlock() {
    // 2x2 block should stay stable even on a toroidal grid.
    std::vector<std::vector<int>> state = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 0},
    };
    Game game(state);
    game.step();
    return gridEquals(game.getGrid(), state);
}

bool testBlinkerOscillator() {
    // Classic blinker on a padded grid to avoid wrap interference.
    std::vector<std::vector<int>> state = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
    };
    std::vector<std::vector<int>> expected = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
    };
    Game game(state);
    game.step();
    return gridEquals(game.getGrid(), expected);
}

bool testObstaclesAreImmutable() {
    std::vector<std::vector<int>> state = {
        {2, 0, 3},
        {0, 1, 0},
        {0, 0, 0},
    };
    Game game(state);
    for (int i = 0; i < 3; ++i) {
        game.step();
        if (game.getGrid()->getCell(0, 0).getState()->value() != 2) return false;
        if (game.getGrid()->getCell(0, 2).getState()->value() != 3) return false;
    }
    return true;
}

bool testGameRunMultipleSteps() {
    // Blinker over two steps should return to initial state.
    std::vector<std::vector<int>> state = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
    };
    Game game(state);
    game.run(2);
    return gridEquals(game.getGrid(), state);
}

}  // namespace

int main() {
    struct Case {
        const char* name;
        bool (*fn)();
    };

    const Case cases[] = {
        {"GridSerializer load/dump", testGridSerializerLoadAndDump},
        {"Toroidal still life block", testToroidalWrappingStillLifeBlock},
        {"Blinker oscillator", testBlinkerOscillator},
        {"Obstacle immutability", testObstaclesAreImmutable},
        {"Game run multi-step", testGameRunMultipleSteps},
    };

    int passed = 0;
    for (const auto &c : cases) {
        const bool ok = c.fn();
        if (ok) {
            std::cout << "[PASS] " << c.name << "\n";
            passed++;
        } else {
            std::cout << "[FAIL] " << c.name << "\n";
        }
    }

    const int total = static_cast<int>(sizeof(cases) / sizeof(cases[0]));
    std::cout << "Summary: " << passed << "/" << total << " passed.\n";
    return passed == total ? 0 : 1;
}
