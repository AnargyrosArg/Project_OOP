///
/// Created by Giann on 12/30/2020.
///

#include "Entity.h"
class Hero;

#ifndef MONSTER_H
#define MONSTER_H

class Monster : public Entity
{
    private:
        int baseDamage;
        int defence;
        double dodgeChance;

    public:
        Monster(string name_, int lvl, int maxHp, int dmg, int def, double dodge);
        ~Monster() override = 0;

        int getDamage() const { return baseDamage; }
        int getDefence() const { return defence; }
        double getDodge() const { return dodgeChance; }

        virtual void print() const;
        void attack(Hero* hero);
};

#endif //MONSTER_H
