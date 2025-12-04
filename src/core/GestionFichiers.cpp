#include <iostream>
#include <fstream>
#include "GestionFichiers.h"
using namespace std;

string GestionFichier::LireFicher(const string ChSource){
    ifstream fichier(ChSource);
        string contenu = "";
        
        if (fichier.is_open()) {
            string ligne;
            while (getline(fichier, ligne)) {
                contenu += ligne + "\n";
            }
            fichier.close();
        } else {
            cerr << "Erreur: Impossible d'ouvrir le fichier " << ChSource << endl;
        }
        return contenu;
}

void GestionFichier::EcrireFichier(const string ChSource, const string Texte){
    ofstream fichier(ChSource);
        
        if (fichier.is_open()) {
            fichier << Texte;
            fichier.close();
        } else {
            cerr << "Erreur: Impossible d'ouvrir le fichier " << ChSource << endl;
        }
}