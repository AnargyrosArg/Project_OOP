///
/// Created by Giann on 12/30/2020.
///

#include <string>

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

    public:
        Entity(string name_, int level_, int maxHealth_);
        virtual ~Entity() = 0;

        string getName() const { return name; }
        int getLevel() const { return level; }
        int getMaxHealth() const { return maxHealth; }
        int getHealth() const { return health; }

        void setMaxHealth(int maxHp) { maxHealth = maxHp; }
        void setHealth(int hp) { health = hp; }
        void setLevel(int lvl) { level = lvl; }
};


#endif //UNTITLED1_ENTITY_H
