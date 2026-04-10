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

class Jeu {
private:
    Joueur joueur;
    CatalogueAct catalogue;

public:
    Jeu(std::string nomJoueur);
    void lancer();
};

#endif