#ifndef MONSTRE_NORMAL_H
#define MONSTRE_NORMAL_H

#include "Monstre.h"

class MonstreNormal : public Monstre {
public:
    MonstreNormal(std::string n, int h, int a, int d)
        : Monstre(n, h, a, d) {
    }

    int getNombreMaxAct() const override { return 2; }
    std::string getCategorie() const override { return "NORMAL"; }
};

#endif