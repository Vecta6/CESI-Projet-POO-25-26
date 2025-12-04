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


bool GestionFichier::LoadGrid(const std::string &path, std::vector<std::vector<int>> &grid, int &rows, int &cols) {
    std::ifstream file(path);
    if (!file) return false;

    if (!(file >> rows >> cols)) return false;
    if (rows<=0 || cols<=0) return false;

    grid.assign(rows, std::vector<int>(cols, 0));

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int v;
            if (!(file >> v)) return false;

            grid[r][c] = v;
        }
    }

    return true;
}