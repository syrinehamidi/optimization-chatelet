#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <string>
#include "Joueur.h"
#include "MonstreNormal.h"
#include "MiniBossMonstre.h"
#include "BossMonstre.h"
#include "Combat.h"
#include "CatalogueAct.h"
using namespace std;

class Jeu {
private:
    Joueur joueur;
    CatalogueAct catalogue;

public:
    Jeu(string nomJoueur);
    void lancer();
};

#endif