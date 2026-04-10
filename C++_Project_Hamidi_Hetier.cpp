#include <iostream>
#include <string>
#include "Jeu.h"

int main() {
    std::string nom;

    std::cout << "Nom du joueur : ";
    std::getline(std::cin, nom);

    Jeu jeu(nom);
    jeu.lancer();

    return 0;
}