#ifndef CATALOGUE_ACT_H
#define CATALOGUE_ACT_H

#include <iostream>
#include <vector>
#include "ActionAct.h"

class CatalogueAct {
private:
    std::vector<ActionAct> actions;

public:
    CatalogueAct() {
        actions.push_back(ActionAct("JOKE", "Tu racontes une blague nulle... il rigole malgre lui.", 20));
        actions.push_back(ActionAct("COMPLIMENT", "Tu complimentes ses ecailles. Il rougit.", 15));
        actions.push_back(ActionAct("DANCE", "Tu fais une danse ridicule. Il est perturbe.", 25));
        actions.push_back(ActionAct("PET", "Tu caresses le monstre. Il se calme.", 30));
        actions.push_back(ActionAct("REASON", "Tu tentes de le raisonner. Il reflechit...", 10));
        actions.push_back(ActionAct("OFFER_SNACK", "Tu lui offres un biscuit. Il adore ca !", 35));
        actions.push_back(ActionAct("INSULT", "Tu insultes le monstre. Il est FURIEUX.", -20));
        actions.push_back(ActionAct("DISCUSS", "Tu lances un debat politique. Il perd patience.", -10));
    }

    void afficherActions(int nombreMax) const {
        int affiche = 0;
        for (int i = 0; i < (int)actions.size() && affiche < nombreMax; i++, affiche++) {
            std::cout << affiche + 1 << ". " << actions[i].id
                << " - " << actions[i].texte
                << "  (Mercy " << (actions[i].impactMercy > 0 ? "+" : "")
                << actions[i].impactMercy << ")" << std::endl;
        }
    }

    ActionAct getAction(int index) const { return actions[index]; }
};

#endif
