#ifndef MONSTRE_H
#define MONSTRE_H

#include <iostream>
#include <string>

class Monstre {
protected:
    std::string nom;
    int hp;
    int hpMax;
    int attaque;
    int defense;
    int mercy;

public:
    Monstre(std::string n, int h, int a, int d);

    virtual void afficher() const;
    void recevoirDegats(int degats);
    void ajouterMercy(int valeur);
    bool estEpargnable() const;
    bool estMort() const;

    std::string getNom() const;
    int getHpMax() const { return hpMax; }
    int getAttaque() const;
    int getDefense() const { return defense; }
    int getMercy() const { return mercy; }

    virtual std::string getCategorie() const = 0;
    virtual int getNombreMaxAct() const = 0;
};

#endif