//
// Created by anarg on 12/29/2020.
//

#ifndef UNTITLED1_ITEM_H
#define UNTITLED1_ITEM_H

#include <string>
#include <iostream>

class Hero;

using namespace std;

class Item {
private:
    string name;
    int cost;
    int levelReq;
    bool equipped;
    bool consumable;
public:
    int getCost()const{return cost;}
    int getLevelReq() const{return levelReq;}
    string getName()const{return name;}
    bool isEquipped() const { return equipped; }
    void setEquipped(bool status) { equipped = status; }
    bool isConsumable() const { return consumable; }
    void setConsumable(bool status) { consumable = status; }
    Item(string name,int level_requirement,int cost);

    virtual void equip(Hero* hero)=0;
    virtual void print();
    virtual ~Item();
};



#endif //UNTITLED1_ITEM_H