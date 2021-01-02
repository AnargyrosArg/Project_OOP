//
// Created by anarg on 1/1/2021.
//

#ifndef UNTITLED1_STRENGTHPOTION_H
#define UNTITLED1_STRENGTHPOTION_H
#include "Potion.h"


class StrengthPotion:public Potion {
private:
public:
    StrengthPotion(int level,int potency,int duration);
    StrengthPotion(int level);
    ~StrengthPotion();
    void equip(Hero* hero) override; /// When we "equip" a potion, we consume it

};


#endif //UNTITLED1_STRENGTHPOTION_H
