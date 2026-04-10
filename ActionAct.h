#ifndef ACTION_ACT_H
#define ACTION_ACT_H

#include <string>
using namespace std;

class ActionAct {
public:
    string id;
    string texte;
    int impactMercy;

    ActionAct(string i, string t, int m)
        : id(i), texte(t), impactMercy(m) {
    }
};

#endif