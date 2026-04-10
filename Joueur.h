#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <string>
#include "Monstre.h"

class Joueur {
private:
    std::string nom;
    int hp;
    int hpMax;
    int attaque;
    int defense;

public:
    Joueur(std::string n);

    void afficher() const;
    void attaquerMonstre(Monstre& monstre);
    void recevoirDegats(int degats);
    bool estVivant() const;
};

#endif