///
/// Created by Giann on 12/30/2020.
///

#include "Entity.h"

#ifndef HERO_H
#define HERO_H

class Hero : public Entity
{
    private:
        int maxMagic;
        int magic;
        int strength;
        int dexterity;
        int agility;
        int money;
        int experience;

    public:
        Hero(string name_, int lvl, int hp, int magic_, int str, int dex, int agil);
        ~Hero() override = 0;

        int getMaxMagic() const { return maxMagic; }
        int getMagic() const { return magic; }
        int getStrength() const { return strength; }
        int getDexterity() const { return dexterity; }
        int getAgility() const { return agility; }
        int getMoney() const { return money; }
        int getExperience() const { return experience; }

        void setMaxMagic(int maxMag) { maxMagic = maxMag; }
        void setMagic(int mag) { magic = mag; }
        void setStrength(int str) { strength = str; }
        void setDexterity(int dex) { dexterity = dex; }
        void setAgility(int agil) { agility = agil; }
        void setMoney(int money_) { money = money_; }
        void setExperience(int exp) { experience = exp; }

        virtual void levelUp() {};
};


#endif //HERO_H
