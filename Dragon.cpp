///
/// Created by Giann on 12/30/2020.
///

#include "Utils.h"
#include "Dragon.h"

/// CONSTRUCTOR
Dragon::Dragon(int lvl) : Monster(getRandomName("../Names/Names.txt"), lvl, lvl*8, lvl*3, lvl, (double) lvl)
{
    cout << "Created Dragon named " << Entity::getName() << ". Stats:" << endl << "Dmg: " << Monster::getDamage() << endl << "Def: "
    << Monster::getDefence() << endl << "Dodge: " << Monster::getDodge() << endl << endl;
}

/// DESTRUCTOR
Dragon::~Dragon()
{
    cout << "Destroyed Dragon named " << Entity::getName() << ". Stats:" << endl << "Dmg: " << Monster::getDamage() << endl << "Def: "
    << Monster::getDefence() << endl << "Dodge: " << Monster::getDodge() << endl << endl;
}

/// PRINT
void Dragon::print() const
{
    cout << endl << "Dragon ";
    Monster::print();
}1