#include <exception>
#include <iostream>
#include <limits>
#include <string>

#include "src/console/Console.h"
#include "src/gui/Gui.h"

int main() {
    try {
        char mode = '\0';
        std::cout << "Choisir le mode (c = console, g = graphique) : ";
        std::cin >> mode;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string inputPath;
        std::cout << "Chemin du fichier d'entree : ";
        std::getline(std::cin, inputPath);

        if (inputPath.empty()) {
            std::cerr << "Chemin du fichier vide.\n";
            return 1;
        }

        if (mode == 'c' || mode == 'C') {
            std::cout << "Nombre d'iterations (0 pour aucune limite fixe) : ";
            std::string line;
            std::getline(std::cin, line);
            int iterations = 0;
            if (!line.empty()) {
                try {
                    iterations = std::stoi(line);
                    if (iterations < 0) {
                        std::cerr << "Le nombre d'iterations doit etre positif.\n";
                        return 1;
                    }
                } catch (const std::exception &) {
                    std::cerr << "Parametre iteration invalide.\n";
                    return 1;
                }
            }

            Console console(inputPath, iterations);
            console.run();
        } else if (mode == 'g' || mode == 'G') {
            Gui gui(inputPath);
            gui.run();
        } else {
            std::cerr << "Mode invalide. Utilisez 'c' ou 'g'.\n";
            return 1;
        }
    } catch (const std::exception &ex) {
        std::cerr << "Erreur: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
