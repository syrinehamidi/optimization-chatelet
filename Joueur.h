#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <string>
#include "Monstre.h"
using namespace std;

class Joueur {
private:
    string nom;
    int hp;
    int hpMax;
    int attaque;
    int defense;
    int victoire;

public:
    Joueur(string n);

    void afficher() const;
    void attaquerMonstre(Monstre& monstre);
    void recevoirDegats(int degats);
    bool estVivant() const;
};

#endif