//
// Created by anarg on 12/30/2020.
//

#include "Potion.h"


void Potion::equip(Hero* hero) {
    cout << "Cannot equip potions! Use directly from inventory"<<endl;
    return;
}

Potion::Potion(string Name,int Cost,int Level,int Potency):Item(Name,Level,Cost),potency(Potency)
{
    cout << "Potion created";
}

Potion::~Potion(){
    cout << "Potion deleted"<<endl;
}
