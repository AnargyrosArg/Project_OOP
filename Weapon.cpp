//
// Created by anarg on 12/29/2020.
//

#include "Weapon.h"

Weapon::Weapon(string name,int cost,int level,int damage, bool two_handed = false):damage(damage),twoHanded(two_handed),Item(name,cost,level){
    cout << "Weapon: "<<getName()<<" created"<<endl;
}

Weapon::~Weapon(){
    cout << "Weapon: " << getName() << " deleted"<<endl;
}