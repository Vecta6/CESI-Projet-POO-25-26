cmake_minimum_required(VERSION 4.0)
project(CESI-Projet-POO-25-26)

set(CMAKE_CXX_STANDARD 20)

add_executable(CESI-Projet-POO-25-26 main.cpp
        src/console/Console.cpp
        src/console/Console.h
        src/core/Grid.cpp
        src/core/Grid.h
        src/core/Game.cpp
        src/core/Game.h
        src/core/Rule/Rule.cpp
        src/core/Rule/Rule.h
        src/core/Rule/Rules/ClassicLifeRule.cpp
        src/core/Rule/Rules/ClassicLifeRule.h
        src/gui/Gui.cpp
        src/gui/Gui.h
        src/core/Cells/Cell.cpp
        src/core/Cells/Cell.h
        src/core/Cells/CellState.h
        src/core/Cells/CellStates/AliveState.cpp
        src/core/Cells/CellStates/AliveState.h
        src/core/Cells/CellStates/DeadState.cpp
        src/core/Cells/CellStates/DeadState.h)
