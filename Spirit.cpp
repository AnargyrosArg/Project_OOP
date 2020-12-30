///
/// Created by Giann on 12/30/2020.
///

#include "Utils.h"
#include "Spirit.h"

/// CONSTRUCTOR
Spirit::Spirit(int lvl) : Monster(getRandomName("../Names/Names.txt"), lvl, lvl*4, lvl, lvl, (double) lvl*3)
{
    cout << "Created Spirit named " << Entity::getName() << ". Stats:" << endl << "Dmg: " << Monster::getDamage() << endl << "Def: "
         << Monster::getDefence() << endl << "Dodge: " << Monster::getDodge() << endl << endl;
}

/// DESTRUCTOR
Spirit::~Spirit()
{
    cout << "Destroyed Spirit named " << Entity::getName() << ". Stats:" << endl << "Dmg: " << Monster::getDamage() << endl << "Def: "
         << Monster::getDefence() << endl << "Dodge: " << Monster::getDodge() << endl << endl;
}