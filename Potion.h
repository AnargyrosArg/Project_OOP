//
// Created by anarg on 12/30/2020.
//

#ifndef UNTITLED1_POTION_H
#define UNTITLED1_POTION_H

#include "Item.h"

enum PotionTypes{Health=0,Strength=1,Dexterity=2,Agility=3};

class Potion : public Item{
private:
    PotionTypes type;
public:
    PotionTypes getType(){return type;}
    int getEffect();
};


#endif //UNTITLED1_POTION_H
