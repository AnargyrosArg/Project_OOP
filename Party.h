//
// Created by anarg on 12/31/2020.
//
#include <vector>
#include "Hero.h"

#ifndef UNTITLED1_PARTY_H
#define UNTITLED1_PARTY_H


class Party {
private:
    vector <Hero*> party;
    vector <Item*> inventory;
public:
    Party(Hero* hero1,Hero* hero2,Hero* hero3);
    Party(Hero* hero1,Hero* hero2);
    Party(Hero* hero);


    void pickUp(Item* item);
    void printInv();
    void equip();

    void print();
};


#endif //UNTITLED1_PARTY_H