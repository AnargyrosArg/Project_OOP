//
// Created by anarg on 12/29/2020.
//

#ifndef UNTITLED1_ITEM_H
#define UNTITLED1_ITEM_H
#include "string"
#include <iostream>
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
    Item(string,int,int);
    virtual ~Item();
};



#endif //UNTITLED1_ITEM_H