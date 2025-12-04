#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "GestionFichiers.h"

std::string GestionFichier::LireFichier(const std::string &ChSource){
    std::ifstream fichier(ChSource);
        std::string contenu;
        
        if (fichier.is_open()) {
            std::string ligne;
            while (getline(fichier, ligne)) {
                contenu += ligne + "\n";
            }
            fichier.close();
        } else {
            std::cerr << "Erreur: Impossible d'ouvrir le fichier " << ChSource << std::endl;
        }
        return contenu;
}

bool GestionFichier::EcrireFichier(const std::string &ChSource, const std::string &Texte){
    std::ofstream fichier(ChSource);

    if (fichier.is_open()) {
        fichier << Texte;
        fichier.close();
    } else {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier " << ChSource << std::endl;
        return false;
    }

    return true;
}


bool GestionFichier::LoadGrid(const std::string &path, std::vector<std::vector<int>> &grid, int &rows, int &cols) {
    std::ifstream fichier(path);
    if (!fichier) return false;

    if (!(fichier >> rows >> cols)) return false;
    if (rows<=0 || cols<=0) return false;

    grid.assign(rows, std::vector<int>(cols, 0));

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int v;
            if (!(fichier >> v)) return false;

            grid[r][c] = v;
        }
    }

    return true;
}