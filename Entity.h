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
        int health;

    public:
        Entity(string name_, int level_, int health_);
        virtual ~Entity() = 0;
        string getName() const { return name; }
        int getLevel() const { return level; }
        int getHealth() const { return health; }
};


#endif //UNTITLED1_ENTITY_H
