///
/// Created by Giann on 12/30/2020.
///



#ifndef HERO_H
#define HERO_H
#include <vector>
#include "Monster.h"
#include "Armour.h"
#include "Weapon.h"
#include "Effects.h"
#include "Spell.h"

class Hero : public Entity
{
    private:
        Weapon* weapon1;
        Weapon* weapon2;
        Armour* armour;
        vector <Spell*> spells;
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
        void setArmour(Armour* armour);
        void equipWeapon(Weapon* weapon);

        bool attack(Monster* monster);
        void learnSpell(Spell* spell);
        bool castSpell(Monster* monster);
        void addEffect(EffectType type,int power,int duration) override;
        void countTurn() override;
        virtual void print();
        void printSpells();
        virtual void levelUp() {};
};


#endif //HERO_H
