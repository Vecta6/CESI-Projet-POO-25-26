#pragma once

#include <string>
#include <vector>

class GestionFichier{
public:
    static std::string LireFichier(const std::string &ChSource);
    static bool EcrireFichier(const std::string &ChSource, const std::string &Texte);
};
