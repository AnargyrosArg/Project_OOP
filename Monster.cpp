///
/// Created by Giann on 12/30/2020.
///

#include "Monster.h"
#include <iostream>

/// CONSTRUCTOR
Monster::Monster(string name_, int lvl, int maxHp, int dmg, int def, double dodge)
: Entity(std::move(name_), lvl, maxHp), baseDamage(dmg), defence(def), dodgeChance(dodge/350) {}

/// DESTRUCTOR
Monster::~Monster() = default;

/// PRINT
void Monster::print() const
{
    cout << Entity::getName() << endl
    << "Level: "<< getLevel() << endl
    << "Health:" << getHealth() << "/" << getMaxHealth() << endl
    << "--------------Stats--------------" << endl <<
    " Dmg: " << getDamage()  <<
    " Def: " << getDefence() <<
    " Dodge: " << getDodge() << endl
    <<"---------------------------------"<< endl << endl;
}