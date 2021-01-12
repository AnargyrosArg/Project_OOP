///
/// Created by Giann on 1/2/2021.
///

#include <string>
#include "Monster.h"

using namespace std;

#ifndef SPELL_H
#define SPELL_H

class Spell
{
    private:
        string name;
        int cost;
        int levelReq;
        int baseDamage;
        int magicCost;
        int power;

    public:
        Spell(string name_, int cost_, int lvl, int dmg, int magicCost_, int power);
        virtual ~Spell();
        string getName() const { return name; }
        int getCost() const { return cost; }
        int getLevelReq() const { return levelReq; }
        int getDamage() const { return baseDamage; }
        int getMagicCost() const { return magicCost; }
        int getPower() const { return power; }

        virtual void cast(Monster* monster) = 0;
        virtual void print() const = 0;
};


#endif //SPELL_H
