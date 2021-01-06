//
// Created by anarg on 1/2/2021.
//

#include "AgilityPotion.h"

/// When we "equip" a potion, we consume it
void AgilityPotion::equip(Hero *hero) {
    if(this->getLevelReq()>hero->getLevel()){
        cout << "Level requirement not met"<<endl;
        return;
    }
    if(hero->getHealth()>0){
        hero->addEffect(AGILITY,getPotency(),getDuration());
        cout << "Added " <<getPotency() <<" Agility buff to " << hero->getName() << " for " << getDuration()<<" rounds"<<endl;
    }else{
        cout << "Can't use on fainted heroes!"<<endl;
    }
}

AgilityPotion::AgilityPotion(int level,int potency,int duration):Potion("Dexterity Potion",100*level,level,potency,duration)
{
    //cout << "Agility potion created"<<endl;
}

AgilityPotion::AgilityPotion(int level):Potion("Dexterity Potion",100*level,level,level*2,3)
{
    //cout << "Agility potion created"<<endl;
}

AgilityPotion::~AgilityPotion(){
    //cout << "Agility Potion deleted" << endl;
}