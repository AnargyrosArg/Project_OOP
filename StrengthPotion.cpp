//
// Created by anarg on 1/1/2021.
//

#include "StrengthPotion.h"

/// When we "equip" a potion, we consume it
void StrengthPotion::equip(Hero *hero) {
    if(hero->getHealth()>0){
        hero->addEffect(STRENGTH,getPotency(),getDuration());
        cout << "Added " <<getPotency() <<" Strength buff to " << hero->getName() << " for " << getDuration()<<" rounds"<<endl;
    }else{
        cout << "Can't use on fainted heroes!"<<endl;
    }
}

StrengthPotion::StrengthPotion(int level,int potency,int duration):Potion("Strength Potion",100*level,level,potency,duration)
{
    cout << "Strength potion created"<<endl;
}

StrengthPotion::StrengthPotion(int level):Potion("Strength Potion",100*level,level,level*2,3)
{
    cout << "Strength potion created"<<endl;
}

StrengthPotion::~StrengthPotion() {
    cout << "Strength Potion deleted" << endl;
}