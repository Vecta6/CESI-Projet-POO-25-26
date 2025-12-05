cmake_minimum_required(VERSION 3.31)
project(CESI-Projet-POO-25-26)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS system window graphics network audio)
if(NOT SFML_FOUND)
    # Fallback sur SFML 3 (Arch) si 2.5 n'est pas disponible.
    find_package(SFML 3 REQUIRED COMPONENTS Graphics System Window Network Audio)
    set(SFML_LIBRARIES SFML::Graphics SFML::System SFML::Window SFML::Network SFML::Audio)
else()
    set(SFML_LIBRARIES
        sfml-system
        sfml-window
        sfml-graphics
        sfml-network
        sfml-audio)
endif()

add_executable(CESI-Projet-POO-25-26 main.cpp
        src/console/Console.cpp
        src/console/Console.h
        src/core/Grid.cpp
        src/core/Grid.h
        src/core/Game.cpp
        src/core/Game.h
        src/core/utils/GridSerializer.cpp
        src/core/utils/GridSerializer.h
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
        src/core/Cells/CellStates/DeadState.h
        src/core/Cells/CellStates/ObstacleAlive.cpp
        src/core/Cells/CellStates/ObstacleAlive.h
        src/core/Cells/CellStates/ObstacleDead.cpp
        src/core/Cells/CellStates/ObstacleDead.h
        src/core/utils/GridSerializer.cpp
        src/core/utils/GridSerializer.h
        src/core/GestionFichiers.cpp
        src/core/GestionFichiers.h)

target_link_libraries(CESI-Projet-POO-25-26 PRIVATE ${SFML_LIBRARIES})
