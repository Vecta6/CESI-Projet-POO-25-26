#pragma once

#include <string>
#include <vector>

class GestionFichier{
public:
    // Read the entire file into a single string (with trailing newlines preserved).
    static std::string LireFichier(const std::string &ChSource);
    // Write the provided text to the target file path.
    static bool EcrireFichier(const std::string &ChSource, const std::string &Texte);
};
