//
// Created by anarg on 1/3/2021.
//

#ifndef UNTITLED1_MARKET_H
#define UNTITLED1_MARKET_H
#include <vector>
#include "Block.h"
#include "Weapon.h"
#include "Armour.h"
#include "StrengthPotion.h"
#include "AgilityPotion.h"
#include "DexterityPotion.h"
#include "HealthPotion.h"
#include "IceSpell.h"
#include "FireSpell.h"
#include "LightningSpell.h"


enum {WEAPONS=3,ARMOURS=2,SPELLS=2,POTIONS=2};

class Market : public Block{
private:
    vector <Item*> items;
    vector <Spell*> spells;
protected:
    void removeFromStock(int itemindex); //protected because its intended for internal use
public:
    Market(int level);
    void event(Party* party);
    void printStock();
    bool purchase(int itemindex,Party* party); //returns if purchase was successfull or not
};


#endif //UNTITLED1_MARKET_H
