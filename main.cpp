#include <exception>
#include <iostream>
#include <string>

#include "src/console/Console.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <fichier_entree> [iterations_max]\n";
        return 1;
    }

    const std::string inputPath = argv[1];
    int iterations = 10;

    if (argc >= 3) {
        try {
            iterations = std::stoi(argv[2]);
            if (iterations < 0) {
                std::cerr << "Le nombre d'iterations doit etre positif.\n";
                return 1;
            }
        } catch (const std::exception &) {
            std::cerr << "Parametre iteration invalide: " << argv[2] << "\n";
            return 1;
        }
    }

    try {
        Console console(inputPath, iterations);
        console.run();
    } catch (const std::exception &ex) {
        std::cerr << "Erreur: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
