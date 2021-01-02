//
// Created by anarg on 1/2/2021.
//

#include "DexterityPotion.h"

/// When we "equip" a potion, we consume it
void DexterityPotion::equip(Hero *hero) {
    if(this->getLevelReq()>hero->getLevel()){
        cout << "Level requirement not met"<<endl;
        return;
    }
    if(hero->getHealth()>0){
        hero->addEffect(DEXTERITY,getPotency(),getDuration());
        cout << "Added " <<getPotency() <<" Dexterity buff to " << hero->getName() << " for " << getDuration()<<" rounds"<<endl;
    }else{
        cout << "Can't use on fainted heroes!"<<endl;
    }
}

DexterityPotion::DexterityPotion(int level,int potency,int duration):Potion("Dexterity Potion",100*level,level,potency,duration)
{
    cout << "Dexterity potion created"<<endl;
}

DexterityPotion::DexterityPotion(int level):Potion("Dexterity Potion",100*level,level,level*2,3)
{
    cout << "Dexterity potion created"<<endl;
}

DexterityPotion::~DexterityPotion() {
    cout << "Strength Potion deleted" << endl;
}