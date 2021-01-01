///
/// Created by Giann on 12/30/2020.
///

#include "Hero.h"
#include <iostream>

/// CONSTRUCTOR
Hero::Hero(string name_, int lvl, int hp, int magic_, int str, int dex, int agil)
: Entity(std::move(name_), lvl, hp), maxMagic(magic_), magic(maxMagic), strength(str), dexterity(dex), agility(agil), money(0), experience(0)
,armour(nullptr),weapon1(nullptr),weapon2(nullptr){}

/// DESTRUCTOR
Hero::~Hero() {}

void Hero::setArmour(Armour *armour) {
    if(getLevel()>=armour->getLevelReq()) {
        armour = armour;
        cout << "Equipped armour "<<armour->getName()<<endl;
        return;
    }else{
        cout << "Level requirement for "<<armour->getName()<<" not met"<<endl;
        return;
    }

}

void Hero::equipWeapon(Weapon* weapon){
    if(weapon->getLevelReq()<=getLevel()){
        if(weapon->isTwoHanded()){
            weapon1=weapon;
            weapon2= nullptr;
            cout << "Equipped "<<weapon->getName()<<" in both hands"<<endl;
            return;
        }else{
            if(weapon1== nullptr){
                weapon1=weapon;
                cout << "Equipped "<<weapon->getName()<<" in one hand"<<endl;
                return;
            }
            if(weapon2== nullptr){
                weapon2=weapon;
                cout << "Equipped "<<weapon->getName()<<" in one hand"<<endl;
                return;
            }
            if(weapon==weapon2 || weapon==weapon1){
                cout << "Item already equipped"<<endl;
                return;
            }
            if(weapon1!= nullptr && weapon2!= nullptr){
                cout << "Swapped "<<weapon1->getName()<<" for "<<weapon->getName()<<endl;
                weapon1=weapon;
                return;
            }
        }
    }else{
        cout << "Level requirement for "<<weapon->getName()<<" not met"<<endl;
    }

}

void Hero::print() {
    cout << Entity::getName()<<endl
    << "Level: "<<getLevel() <<endl
    << "Health:" <<getHealth()<<"/"<<getMaxHealth()<<endl
    <<"Magic: "<<getMagic() <<"/"<< getMaxMagic()<<endl
    << "--------------Stats--------------" << endl <<
    "Mag: " << Hero::getMaxMagic()  <<
    " Str: "<< Hero::getStrength()  <<
    " Dex: " << Hero::getDexterity() <<
    " Agil: " << Hero::getAgility()<<endl
    <<"---------------------------------"<< endl;
    if(weapon1!= nullptr){
        cout << "Weapon 1: "<<weapon1->getName()<<endl;
    }
    if(weapon2!= nullptr){
        cout << "Weapon 2: "<<weapon2->getName()<<endl;
    }
    if(armour!=nullptr){
        cout << "Armour: "<<armour->getName() <<endl;
    }
    cout << endl;
}

void Hero::addEffect(EffectType type,int power, int duration) {
    effects.push_back(new Effects(type,power,duration));
    if(type==STRENGTH){
        setStrength(getStrength()+power);
        return;
    }
    if(type==DEXTERITY){
        setStrength(getDexterity()+power);
        return;
    }
    if(type==AGILITY){
        setAgility(getAgility()+power);
        return;
    }
}

void Hero::countTurn() {
    for(int i=0;i<effects.size();i++){
        effects.at(i)->setDuration(effects.at(i)->getDuration()-1);
        if(effects.at(i)->getDuration()==0){
            if(effects.at(i)->getType()==STRENGTH){
                setStrength(getStrength()-effects.at(i)->getPower());
            }
            else if(effects.at(i)->getType()==DEXTERITY){
                setDexterity(getDexterity()-effects.at(i)->getPower());
            }
            else if(effects.at(i)->getType()==AGILITY){
                setAgility(getAgility()-effects.at(i)->getPower());
            }
            effects.erase(effects.begin()+i);
        }
    }
}

