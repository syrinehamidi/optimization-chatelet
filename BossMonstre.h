#ifndef BOSS_MONSTRE_H
#define BOSS_MONSTRE_H

#include "Monstre.h"

class BossMonstre : public Monstre {
public:
    BossMonstre(std::string n, int h, int a, int d)
        : Monstre(n, h, a, d) {
    }

    int getNombreMaxAct() const override { return 4; }
    std::string getCategorie() const override { return "BOSS"; }
};

#endif#endif