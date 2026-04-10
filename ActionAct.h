#ifndef ACTION_ACT_H
#define ACTION_ACT_H

#include <string>

class ActionAct {
public:
    std::string id;
    std::string texte;
    int impactMercy;

    ActionAct(std::string i, std::string t, int m)
        : id(i), texte(t), impactMercy(m) {
    }
};

#endif
