#include <iostream>
#include <string>
#include "Jeu.h"
using namespace std;

int main() {
    string nom;

    cout << "Nom du joueur : ";
    getline(std::cin, nom);

    Jeu jeu(nom);
    jeu.lancer();

    return 0;
}