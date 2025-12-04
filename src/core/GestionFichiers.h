#pragma once

#include <iostream>
using namespace std;

class GestionFichier{
public:
    static string LireFicher(const string ChSource);
    static void EcrireFichier(const string ChSource, const string Texte);
};