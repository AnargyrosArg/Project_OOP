///
/// Created by Giann on 12/30/2020.
///

#include "Utils.h"
#include "Exoskeleton.h"

/// CONSTRUCTOR
Exoskeleton::Exoskeleton(int lvl) : Monster(getRandomName("../Names/Names.txt"), lvl, lvl*50, lvl, lvl*3, (double) lvl)
{
    cout << "Created Exoskeleton named " << Entity::getName() << ". Stats:" << endl << "Hp: " << Entity::getMaxHealth()
    << endl << "Dmg: " << Monster::getDamage() << endl << "Def: "
    << Monster::getDefence() << endl << "Dodge: " << Monster::getDodge() << endl << endl;
}

/// DESTRUCTOR
Exoskeleton::~Exoskeleton()
{
    cout << "Destroyed Exoskeleton named " << Entity::getName() << ". Stats:" << endl << "Dmg: " << Monster::getDamage() << endl << "Def: "
         << Monster::getDefence() << endl << "Dodge: " << Monster::getDodge() << endl << endl;
}

/// PRINT
void Exoskeleton::print() const
{
    cout << endl << endl << "Exoskeleton: ";
    Monster::print();
}