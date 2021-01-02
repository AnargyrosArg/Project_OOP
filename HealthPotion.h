//
// Created by anarg on 12/31/2020.
//

#ifndef UNTITLED1_HEALTHPOTION_H
#define UNTITLED1_HEALTHPOTION_H
#include "Potion.h"

class HealthPotion: public Potion {
private:

public:
    HealthPotion(int level);
    ~HealthPotion();
    void equip(Hero* hero) override; /// When we "equip" a potion, we consume it
};


#endif //UNTITLED1_HEALTHPOTION_H
