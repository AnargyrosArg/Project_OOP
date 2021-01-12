///
/// Created by Giann on 12/30/2020.
///

using namespace std;

#include "Entity.h"
#include <iostream>

/// CONSTRUCTOR
Entity::Entity(string name_, int level_, int health_) : name(std::move(name_)), level(level_), maxHealth(health_), health(maxHealth)
{
    ///cout << "Created level " << level << " entity named " << name << " with " << health << " health." << endl;
}

/// DESTRUCTOR
Entity::~Entity()
{
    for(int i=0;i<effects.size();i++){
        delete effects.at(i);
    }
    ///cout << "Destroyed level " << level << " entity named " << name << " with " << health << " health." << endl;
}

/// CHECK DEAD
bool Entity::checkDead() const
{
    if (health <= 0) return true;
    return false;
}