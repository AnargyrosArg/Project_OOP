//
// Created by anarg on 12/30/2020.
//

#include "Potion.h"


void Potion::equip(Hero* hero) {
    cout << "Cannot equip potions! Use directly from inventory"<<endl;
    return;
}

Potion::Potion(string Name,int Cost,int Level,int Potency):Item(Name,Level,Cost),potency(Potency),duration(0)
{
    cout << "Potion created" << endl;
}

Potion::~Potion(){
    cout << "Potion deleted"<<endl;
}

Potion::Potion(string Name,int Cost,int Level,int Potency,int Duration):Item(Name,Level,Cost),potency(Potency),duration(Duration)
{
    cout << "Potion created" << endl;
}