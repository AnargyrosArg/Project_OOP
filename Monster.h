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
        void setDamage(int dmg) { baseDamage = dmg; }
        void setDefence(int def) { defence = def; }
        void setDodge(double dodge) { dodgeChance = dodge; }

        virtual void print() const;
        void attack(Hero* hero);
        void addEffect(EffectType type,int power,int duration) override;
        void countTurn() override;
};

#endif //MONSTER_H
