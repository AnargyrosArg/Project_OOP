//
// Created by anarg on 12/30/2020.
//

#include "Armour.h"
#include "Hero.h"

Armour::Armour(string name, int cost, int level, int defence)
:Item(name,level,cost),defence(defence){
    cout << "Armour "<<getName()<<" created"<<endl;
}
Armour::Armour(int level)
:Item(getRandomName("../Names/Armours.txt"),level,(100*level)+rand()%(10*level)),defence((level*10+rand()%level)/2){
    /*cout << "Generated random Armour" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Defence: " << getDefence() << endl;
    cout << "Cost: " << getCost() << endl;
    cout << "Level: " << getLevelReq() << endl << endl;*/
}

void Armour::print() {
    cout << "Armour ";
    Item::print();
}

void Armour::equip(Hero *hero) {
    hero->setArmour(this);
}
