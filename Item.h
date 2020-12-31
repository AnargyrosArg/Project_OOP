//
// Created by anarg on 12/29/2020.
//
#include "string"
#include <iostream>
#include "Hero.h"

#ifndef UNTITLED1_ITEM_H
#define UNTITLED1_ITEM_H


using namespace std;

class Item {
private:
    string name;
    int cost;
    int levelReq;
public:
    int getCost()const{return cost;}
    int getLevelReq() const{return levelReq;}
    string getName()const{return name;}
    Item(string name,int level_requirement,int cost);

    virtual void equip(Hero* hero)=0;
    virtual void print();
    virtual ~Item();
};



#endif //UNTITLED1_ITEM_H