#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "GestionFichiers.h"

std::string GestionFichier::LireFichier(const std::string &ChSource){
    std::ifstream file(ChSource);
        std::string content;
        
        if (file.is_open()) {
            std::string ligne;
            while (getline(file, ligne)) {
                content += ligne + "\n";
            }
            file.close();
        } else {
            std::cerr << "Erreur: Impossible d'ouvrir le fichier " << ChSource << std::endl;
        }
        return content;
}

bool GestionFichier::EcrireFichier(const std::string &ChSource, const std::string &Texte){
    std::ofstream file(ChSource);

    if (file.is_open()) {
        file << Texte;
        file.close();
    } else {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier " << ChSource << std::endl;
        return false;
    }

    return true;
}