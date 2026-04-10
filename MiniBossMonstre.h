#ifndef MINI_BOSS_MONSTRE_H
#define MINI_BOSS_MONSTRE_H

#include "Monstre.h"

class MiniBossMonstre : public Monstre {
public:
    MiniBossMonstre(std::string n, int h, int a, int d)
        : Monstre(n, h, a, d) {
    }

    int getNombreMaxAct() const override { return 3; }
    std::string getCategorie() const override { return "MINIBOSS"; }
};

#endif