#include "Joueur.h"
using namespace std;

Joueur::Joueur(string n)
    : nom(n), hp(100), hpMax(100), attaque(10), defense(5) {
}

void Joueur::afficher() const {
    cout << nom << " HP: " << hp << "/" << hpMax << endl;
}

void Joueur::attaquerMonstre(Monstre& monstre) {
    monstre.recevoirDegats(attaque);
    cout << "Vous infligez " << attaque << " degats !" << endl;
}

void Joueur::recevoirDegats(int degats) {
    hp -= degats;
    if (hp < 0) hp = 0;
}

bool Joueur::estVivant() const { return hp > 0; }