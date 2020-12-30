///
/// Created by Giann on 12/30/2020.
///

using namespace std;

#include "Entity.h"
#include <iostream>

/// CONSTRUCTOR
Entity::Entity(string name_, int level_, int health_) : name(std::move(name_)), level(level_), health(health_)
{
    cout << "Created level " << level << " entity named " << name << " with " << health << " health." << endl;
}

/// DESTRUCTOR
Entity::~Entity()
{
    cout << "Destroyed level " << level << " entity named " << name << " with " << health << " health." << endl;
}