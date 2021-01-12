//
// Created by anarg on 12/31/2020.
//
#include <vector>
#include "Hero.h"

#ifndef UNTITLED1_PARTY_H
#define UNTITLED1_PARTY_H


class Party
{
    private:
        vector <Hero*> party;
        vector <Item*> inventory;
        int money;
    public:
        Party(Hero* hero1,Hero* hero2,Hero* hero3);
        Party(Hero* hero1,Hero* hero2);
        Party(Hero* hero);
        ~Party();

        int getMoney(){return money;}
        int getLevel();

        vector <Hero*>& getHeroes(){return party;}
        void setMoney(int amount){money=amount;}
        void pickUp(Item* item);
        void printInv();
        void useItem(Hero* hero = nullptr);
        void print();
        int getItemCount(){return inventory.size();}
        vector <Item*>& getInv(){return inventory;}
};


#endif //UNTITLED1_PARTY_H
