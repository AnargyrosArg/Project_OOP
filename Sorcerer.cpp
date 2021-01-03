///
/// Created by Giann on 12/30/2020.
///

#include "Sorcerer.h"

using namespace std;

/// CONSTRUCTOR
Sorcerer::Sorcerer(int lvl) : Hero(getRandomName("../Names/Names.txt"), lvl, lvl*6, lvl*4, lvl, lvl*4, lvl*3)
{
    cout << "Created Sorcerer named " << Entity::getName() << ". Stats:" << endl << "Hp: " << Entity::getMaxHealth()
    << endl << "Mag: " << Hero::getMaxMagic() << endl << "Str: " << Hero::getStrength() << endl
    << "Dex: " << Hero::getDexterity() << endl << "Agil: " << Hero::getAgility() << endl << endl;
}

/// DESTRUCTOR
Sorcerer::~Sorcerer()
{
    cout << "Destroyed Sorcerer named " << Entity::getName() << ". Stats:" << endl << "Mag: " << Hero::getMaxMagic() << endl << "Str: "
         << Hero::getStrength() << endl << "Dex: " << Hero::getDexterity() << endl << "Agil: " << Hero::getAgility() << endl << endl;
}

/// LEVEL UP
void Sorcerer::levelUp()
{
    Entity::setLevel(Entity::getLevel()+1); /// level up!
    Hero::setExperience(0); /// reset exp
    Hero::setAgility(Hero::getAgility() + 3); /// Sorcerer is proficient in agility
    Hero::setStrength(Hero::getStrength() + 1); /// Sorcerer is not proficient in strength
    Hero::setDexterity(Hero::getDexterity() + 4); /// Sorcerer is proficient in dexterity
    Hero::setMaxMagic(Hero::getMaxMagic() + 4); /// max magic increase
    Entity::setMaxHealth(Entity::getMaxHealth()+6); /// max health increase

    cout << "Sorcerer named " << Entity::getName() << " leveled up to level " << Entity::getLevel() << "!" << endl << endl;
}

void Sorcerer::print() {
    cout << "Sorcerer: ";
    Hero::print();
}
