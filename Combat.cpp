#include "Combat.h"
using namespace std;

Combat::Combat(Joueur& j, Monstre& m, CatalogueAct& c)
    : joueur(j), monstre(m), catalogue(c) {
}

void Combat::lancer() {
    cout << "\n=== COMBAT : " << monstre.getNom()
        << " [" << monstre.getCategorie() << "] ===" << endl;

    while (joueur.estVivant() && !monstre.estMort()) {
        cout << "\n";
        joueur.afficher();
        monstre.afficher();

        cout << "\n1. FIGHT  2. ACT  3. MERCY" << endl;
        cout << "Choix : ";
        int choix;
        cin >> choix;

        if (choix == 1) {
            joueur.attaquerMonstre(monstre);
            if (monstre.estMort()) {
                cout << monstre.getNom() << " est vaincu !" << endl;
                break;
            }
        }
        else if (choix == 2) {
            int nbAct = monstre.getNombreMaxAct();
            catalogue.afficherActions(nbAct);
            cout << "Choisissez une action (1-" << nbAct << ") : ";
            int choixAct;
            cin >> choixAct;
            choixAct--;
            if (choixAct >= 0 && choixAct < nbAct) {
                ActionAct action = catalogue.getAction(choixAct);
                cout << action.texte << endl;
                monstre.ajouterMercy(action.impactMercy);
            }
            else {
                cout << "Action invalide." << endl;
                continue;
            }
        }
        else if (choix == 3) {
            if (monstre.estEpargnable()) {
                cout << monstre.getNom() << " est epargne !" << endl;
                break;
            }
            else {
                cout << "Mercy insuffisant ("
                    << monstre.getMercy() << "/100)." << endl;
                continue;
            }
        }
        else {
            cout << "Choix invalide." << endl;
            continue;
        }

        // Tour du monstre
        if (!monstre.estMort()) {
            cout << monstre.getNom() << " attaque !" << endl;
            joueur.recevoirDegats(monstre.getAttaque());
        }
    }

    if (!joueur.estVivant())
        cout << "Vous avez perdu !" << endl;
}