#ifndef COMBAT_H
#define COMBAT_H

#include <iostream>
#include "Joueur.h"
#include "Monstre.h"
#include "CatalogueAct.h"
using namespace std;

class Combat {
private:
    Joueur& joueur;
    Monstre& monstre;
    CatalogueAct& catalogue;

public:
    Combat(Joueur& j, Monstre& m, CatalogueAct& c);
    void lancer();
};

#endif