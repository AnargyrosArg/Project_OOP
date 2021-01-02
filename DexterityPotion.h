//
// Created by anarg on 1/2/2021.
//

#ifndef UNTITLED1_DEXTERITYPOTION_H
#define UNTITLED1_DEXTERITYPOTION_H
#include "Potion.h"

class DexterityPotion:public Potion {
    private:
    public:
        DexterityPotion(int level,int potency,int duration);
        DexterityPotion(int level);
        ~DexterityPotion();
        void equip(Hero* hero) override; /// When we "equip" a potion, we consume it




};


#endif //UNTITLED1_DEXTERITYPOTION_H
