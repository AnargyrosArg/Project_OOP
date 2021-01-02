//
// Created by anarg on 1/2/2021.
//

#ifndef UNTITLED1_AGILITYPOTION_H
#define UNTITLED1_AGILITYPOTION_H
#include "Potion.h"

class AgilityPotion:public Potion {
private:
public:
    AgilityPotion(int level,int potency,int duration);
    AgilityPotion(int level);
    ~AgilityPotion();
    void equip(Hero* hero) override; /// When we "equip" a potion, we consume it
};


#endif //UNTITLED1_AGILITYPOTION_H
