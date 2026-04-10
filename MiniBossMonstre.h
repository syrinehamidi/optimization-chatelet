#ifndef MINI_BOSS_MONSTRE_H
#define MINI_BOSS_MONSTRE_H

#include "Monstre.h"
using namespace std;

class MiniBossMonstre : public Monstre {
public:
    MiniBossMonstre(string n, int h, int a, int d)
        : Monstre(n, h, a, d) {
    }

    int getNombreMaxAct() const override { return 3; }
    string getCategorie() const override { return "MINIBOSS"; }
};

#endif