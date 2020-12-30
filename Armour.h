//
// Created by anarg on 12/30/2020.
//

#ifndef UNTITLED1_ARMOUR_H
#define UNTITLED1_ARMOUR_H


#include "Item.h"
#include "Utils.h"

class Armour : public Item{
private:
    int defence;
public:
    int getDefence(){return defence;}
    Armour(int level);
    Armour(string name, int cost, int level, int defence);
};


#endif //UNTITLED1_ARMOUR_H
