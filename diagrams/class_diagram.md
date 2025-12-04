```mermaid
classDiagram
    %% --- Logique métier ---

    class Game {
        - Grid* grid
        - Rule* rule

        Game(int width, int height, int[][] grid)
        ~Game()
        + getGrid() Grid*
        + run(int stepNumber) void
        + step() void
    }

    class Grid {
        - int columns
        - int lines
        - Cell[][] cells

        Grid(string filePath)
        ~Grid()
        + getCell(int line, int column) Cell&
        + countAliveNeighbours(int line, int column) int
        + step(Rule* rule) void
    }

    class Cell {
        - CellState* state

        Cell()
        Cell(int state)
        Cell(CellState* initialState)
        ~Cell()

        + setState(CellState* newState) void
        + getState() const CellState*
    }

    class CellState {
        <<abstract>>
        CellState()
        virtual ~CellState()
        + virtual isAlive() bool
        + virtual symbol() char
        + virtual value() int
        + virtual canBeModified() bool
    }

    class AliveState {
        + isAlive() bool
        + symbol() char
        + value() int
        + canBeModified() bool
    }

    class DeadState {
        + isAlive() bool
        + symbol() char
        + value() int
        + canBeModified() bool
    }

    class Rule {
        <<abstract>>
        + virtual computeNextState(Cell& cell, int aliveNeighbours)* CellState*
        ~Rule()
    }

    class ClassicLifeRule {
        + computeNextState(Cell& cell, int aliveNeighbours) CellState*
    }

    class Console {
        # Game game

        Console(string filePath, int steps)
        Console(string filePath)

        + virtual showCurrentGrid() void

    }

    class Gui {
        - Game* game
        - RenderWindow* window
        - int cellSize
        - float iterationDelay
        - Clock clock
        - bool paused
        - Font font    
        - Text statusText
        - Text speedText
        - Text helpText
        + Gui(string filePath, int cellSize)
        + ~Gui()
        + render() void
        + handleEvents() void
        + reset() void
        + update() void
        + run() void
    }

    %% --- Relations ---

    Game --> Grid : possède
    Game --> Rule : utilise

    Grid "1" o-- "many" Cell
    Cell o-- CellState

    CellState <|-- AliveState
    CellState <|-- DeadState

    Rule <|-- ClassicLifeRule
    Console o-- Game
    Gui --|> Console

```