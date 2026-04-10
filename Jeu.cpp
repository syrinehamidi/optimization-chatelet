#include "Jeu.h"
using namespace std;

Jeu::Jeu(string nomJoueur) : joueur(nomJoueur) {}

void Jeu::lancer() {
    cout << "=== ALTERDUNE ===" << endl;
    joueur.afficher();

    MonstreNormal   m1("Monstre Normal", 30, 7, 1);
    MiniBossMonstre m2("Mimi Boss Monstre", 45, 10, 2);
    BossMonstre     m3("Boos Monstre", 80, 15, 4);

    cout << "\n--- Combat 1 ---" << endl;
    Combat c1(joueur, m1, catalogue);
    c1.lancer();

    if (!joueur.estVivant()) return;

    cout << "\n--- Combat 2 ---" << endl;
    Combat c2(joueur, m2, catalogue);
    c2.lancer();

    if (!joueur.estVivant()) return;

    cout << "\n--- Combat 3 ---" << endl;
    Combat c3(joueur, m3, catalogue);
    c3.lancer();
}