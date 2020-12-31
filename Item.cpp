//
// Created by anarg on 12/29/2020.
//

#include "Item.h"



Item::Item(string Name,int level_requirement,int cost):name(move(Name)),levelReq(level_requirement),cost(cost){
    cout << "Item " << getName() << " Created"<< endl;
}

Item::~Item(){
    cout<< "Item "<<getName()<<" Deleted"<<endl;
}

void Item::print() {
    cout << getName();
}

