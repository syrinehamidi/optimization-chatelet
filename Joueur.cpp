#include "Joueur.h"

Joueur::Joueur(std::string n)
    : nom(n), hp(100), hpMax(100), attaque(10), defense(5) {
}

void Joueur::afficher() const {
    std::cout << nom << " HP: " << hp << "/" << hpMax << std::endl;
}

void Joueur::attaquerMonstre(Monstre& monstre) {
    monstre.recevoirDegats(attaque);
}

void Joueur::recevoirDegats(int degats) {
    hp -= degats;
    if (hp < 0) {
        hp = 0;
    }
}

bool Joueur::estVivant() const {
    return hp > 0;
}