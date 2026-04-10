#include "Combat.h"

Combat::Combat(Joueur& j, Monstre& m, CatalogueAct& c)
    : joueur(j), monstre(m), catalogue(c) {
}

void Combat::lancer() {
    std::cout << "\n=== COMBAT : " << monstre.getNom()
        << " [" << monstre.getCategorie() << "] ===" << std::endl;

    while (joueur.estVivant() && !monstre.estMort()) {
        std::cout << "\n";
        joueur.afficher();
        monstre.afficher();

        std::cout << "\n1. FIGHT  2. ACT  3. MERCY" << std::endl;
        std::cout << "Choix : ";
        int choix;
        std::cin >> choix;

        if (choix == 1) {
            joueur.attaquerMonstre(monstre);
            if (monstre.estMort()) {
                std::cout << monstre.getNom() << " est vaincu !" << std::endl;
                break;
            }
        }
        else if (choix == 2) {
            int nbAct = monstre.getNombreMaxAct();
            catalogue.afficherActions(nbAct);
            std::cout << "Choisissez une action (1-" << nbAct << ") : ";
            int choixAct;
            std::cin >> choixAct;
            choixAct--;
            if (choixAct >= 0 && choixAct < nbAct) {
                ActionAct action = catalogue.getAction(choixAct);
                std::cout << action.texte << std::endl;
                monstre.ajouterMercy(action.impactMercy);
            }
            else {
                std::cout << "Action invalide." << std::endl;
                continue;
            }
        }
        else if (choix == 3) {
            if (monstre.estEpargnable()) {
                std::cout << monstre.getNom() << " est epargne !" << std::endl;
                break;
            }
            else {
                std::cout << "Mercy insuffisant ("
                    << monstre.getMercy() << "/100)." << std::endl;
                continue;
            }
        }
        else {
            std::cout << "Choix invalide." << std::endl;
            continue;
        }

        // Tour du monstre
        if (!monstre.estMort()) {
            std::cout << monstre.getNom() << " attaque !" << std::endl;
            joueur.recevoirDegats(monstre.getAttaque());
        }
    }

    if (!joueur.estVivant())
        std::cout << "Vous avez perdu !" << std::endl;
}