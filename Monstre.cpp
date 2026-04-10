#include "Monstre.h"

Monstre::Monstre(std::string n, int h, int a, int d)
    : nom(n), hp(h), hpMax(h), attaque(a), defense(d), mercy(0) {
}

void Monstre::afficher() const {
    std::cout << nom << " [" << getCategorie() << "]"
        << "  HP: " << hp << "/" << hpMax
        << "  Mercy: " << mercy << "/100" << std::endl;
}

void Monstre::recevoirDegats(int degats) {
    hp -= degats;
    if (hp < 0) hp = 0;
}

void Monstre::ajouterMercy(int valeur) {
    mercy += valeur;
    if (mercy > 100) mercy = 100;
    if (mercy < 0)   mercy = 0;
    std::cout << "Mercy : " << mercy << "/100" << std::endl;
}

bool Monstre::estEpargnable() const { return mercy >= 100; }
bool Monstre::estMort() const { return hp <= 0; }
std::string Monstre::getNom() const { return nom; }
int Monstre::getAttaque() const { return attaque; }