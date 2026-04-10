#include "Jeu.h"

Jeu::Jeu(std::string nomJoueur) : joueur(nomJoueur) {}

void Jeu::lancer() {
    std::cout << "=== ALTERDUNE ===" << std::endl;
    joueur.afficher();

    // 3 monstres de categories differentes pour montrer le polymorphisme
    MonstreNormal   m1("Miniboss", 30, 7, 1);
    MiniBossMonstre m2("Boss", 45, 10, 2);
    BossMonstre     m3("MegaBoss", 80, 15, 4);

    std::cout << "\n--- Combat 1 ---" << std::endl;
    Combat c1(joueur, m1, catalogue);
    c1.lancer();

    if (!joueur.estVivant()) return;

    std::cout << "\n--- Combat 2 ---" << std::endl;
    Combat c2(joueur, m2, catalogue);
    c2.lancer();

    if (!joueur.estVivant()) return;

    std::cout << "\n--- Combat 3 ---" << std::endl;
    Combat c3(joueur, m3, catalogue);
    c3.lancer();
}