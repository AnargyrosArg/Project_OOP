//
// Created by anarg on 12/30/2020.
//

#ifndef UNTITLED1_POTION_H
#define UNTITLED1_POTION_H

#include "Item.h"
#include "Hero.h"
#include "Effects.h"

class Potion : public Item{
private:
    int potency;
    int duration;
public:
    void equip(Hero* hero) override = 0; /// When we "equip" a potion, we consume it
    Potion(string Name,int Cost,int Level,int Potency,int Duration);
    Potion(string Name,int Cost,int Level,int Potency);
    virtual ~Potion();
    int getPotency() const{return potency;}
    int getDuration(){return duration;}
};


#endif //UNTITLED1_POTION_H
