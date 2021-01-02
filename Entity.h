///
/// Created by Giann on 12/30/2020.
///

#include <string>
#include <vector>
#include "Effects.h"

using namespace std;

#ifndef UNTITLED1_ENTITY_H
#define UNTITLED1_ENTITY_H

class Entity
{
    private:
        string name;
        int level;
        int maxHealth;
        int health;
        vector <Effects*> effects;

    public:
        Entity(string name_, int level_, int maxHealth_);
        virtual ~Entity() = 0;

        string getName() const { return name; }
        int getLevel() const { return level; }
        int getMaxHealth() const { return maxHealth; }
        int getHealth() const { return health; }
        vector <Effects*>& getEffects(){ return effects; }

        void setMaxHealth(int maxHp) { maxHealth = maxHp; }
        void setHealth(int hp) { health = hp; }
        void setLevel(int lvl) { level = lvl; }
        virtual void countTurn() {}
        virtual void addEffect(EffectType type,int power,int duration) {}
};


#endif //UNTITLED1_ENTITY_H
