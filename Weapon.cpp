//
// Created by anarg on 12/29/2020.
//

#include "Weapon.h"

Weapon::Weapon(string name,int cost,int level,int damage, bool two_handed = false):damage(damage),twoHanded(two_handed),Item(name,cost,level){
    cout << "Weapon: "<<getName()<<" created"<<endl;
}
Weapon::Weapon(int level):Item(getRandomName("../Names/Weapons.txt"),level,
 (100*level)+rand()%(10*level)),damage((level*10+rand()%level)),twoHanded(rand()%1){
    cout << "Generated random weapon" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Damage: " << getDamage() << endl;
    cout << "Cost: " << getCost() << endl;
    cout << (twoHanded ? "Two Handed" : "One Handed ") << endl;
    cout << "Level: " << getLevelReq() << endl;
}

Weapon::~Weapon(){
    cout << "Weapon: " << getName() << " deleted"<<endl;
}

void Weapon::print() {
    cout << (isTwoHanded() ? "Two Handed " : "One Handed ");
    cout << "Weapon ";
    Item::print();
}

void Weapon::equip(Hero *hero) {
    hero->equipWeapon(this);
}

