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
    cout << Entity::getName()<<" Level: "<<getLevel() <<endl << "---Stats---" << endl << "Mag: " << Hero::getMaxMagic() << endl << "Str: "
         << Hero::getStrength() << endl << "Dex: " << Hero::getDexterity() << endl << "Agil: " << Hero::getAgility() << endl;
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
