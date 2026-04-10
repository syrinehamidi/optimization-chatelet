#ifndef BOSS_MONSTRE_H
#define BOSS_MONSTRE_H

#include "Monstre.h"
using namespace std;

class BossMonstre : public Monstre {
public:
    BossMonstre(string n, int h, int a, int d)
        : Monstre(n, h, a, d) {
    }

    int getNombreMaxAct() const override { return 4; }
    string getCategorie() const override { return "BOSS"; }
};

#endif