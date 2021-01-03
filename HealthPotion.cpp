//
// Created by anarg on 12/31/2020.
//

#include "HealthPotion.h"

/// When we "equip" a potion, we consume it
void HealthPotion::equip(Hero *hero) {
    if(hero->getHealth()>0){
        hero->setHealth(hero->getHealth()+getPotency());
        if(hero->getHealth()>hero->getMaxHealth()){
            hero->setHealth(hero->getMaxHealth());
        }
    }else{
        cout << "Can't use on fainted heroes!"<<endl;
    }
}

HealthPotion::HealthPotion(int level):Potion("Health Potion",100*level,level,5*level)
{
    cout << "Health potion created"<<endl << endl;
}

HealthPotion::~HealthPotion() {
    cout << "Health Potion deleted" << endl;
}