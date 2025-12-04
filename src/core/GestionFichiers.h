#pragma once

#include <string>
#include <vector>

class GestionFichier{
public:
    GestionFichier() = default;
    ~GestionFichier() = default;

    static std::string LireFichier(const std::string &ChSource);
    static bool EcrireFichier(const std::string &ChSource, const std::string &Texte);

    static bool LoadGrid(const std::string &path, std::vector<std::vector<int>> &grid, int &rows, int &cols);
};
