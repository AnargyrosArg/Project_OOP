//
// Created by anarg on 12/30/2020.
//

#include "Potion.h"

Potion::Potion(string Name,int Cost,int Level,int Potency):Item(std::move(Name),Level,Cost),potency(Potency),duration(0)
{
    Item::setConsumable(true);
    //cout << "Potion created" << endl;
}

Potion::~Potion(){
    //cout << "Potion deleted"<<endl;
}

Potion::Potion(string Name,int Cost,int Level,int Potency,int Duration):Item(std::move(Name),Level,Cost),potency(Potency),duration(Duration)
{
    Item::setConsumable(true);
    //cout << "Potion created" << endl;
}