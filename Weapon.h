//
// Created by anarg on 12/29/2020.
//

#ifndef UNTITLED1_WEAPON_H
#define UNTITLED1_WEAPON_H
#include "Item.h"
#include "Utils.h"

class Weapon : public Item{
private:
    int damage;
    bool twoHanded;
public:
    int getDamage()const{return damage;}
    int isTwoHanded()const{return twoHanded;}
    Weapon(string name, int cost, int level, int damage, bool two_handed);
    Weapon(int level);
    void print();
    void equip(Hero* hero);
    ~Weapon();
};


#endif //UNTITLED1_WEAPON_H
