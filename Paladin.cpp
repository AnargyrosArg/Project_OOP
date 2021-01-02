///
/// Created by Giann on 12/30/2020.
///

#include "Paladin.h"

using namespace std;

/// CONSTRUCTOR
Paladin::Paladin(int lvl) : Hero(getRandomName("../Names/Names.txt"), lvl, lvl*8, lvl*3, lvl*3, lvl*3, lvl)
{
    cout << "Created Paladin named " << Entity::getName() << ". Stats:" << endl << "Hp: " << Entity::getMaxHealth()
    << endl << "Mag: " << Hero::getMaxMagic() << endl << "Str: " << Hero::getStrength() << endl
    << "Dex: " << Hero::getDexterity() << endl << "Agil: " << Hero::getAgility() << endl << endl;
}

/// DESTRUCTOR
Paladin::~Paladin()
{
    cout << "Destroyed Paladin named " << Entity::getName() << ". Stats:" << endl << "Mag: " << Hero::getMaxMagic() << endl << "Str: "
         << Hero::getStrength() << endl << "Dex: " << Hero::getDexterity() << endl << "Agil: " << Hero::getAgility() << endl << endl;
}

/// LEVEL UP
void Paladin::levelUp()
{
    Entity::setLevel(Entity::getLevel()+1); /// level up!
    Hero::setExperience(0); /// reset exp
    Hero::setAgility(Hero::getAgility() + 1); /// Paladin is not proficient in agility
    Hero::setStrength(Hero::getStrength() + 3); /// Paladin is proficient in strength
    Hero::setDexterity(Hero::getDexterity() + 3); /// Paladin is proficient in dexterity
    Hero::setMaxMagic(Hero::getMaxMagic() + 3); /// max magic increase
    Entity::setMaxHealth(Entity::getMaxHealth()+8); /// max health increase

    cout << "Paladin named " << Entity::getName() << " leveled up to level " << Entity::getLevel() << "!" << endl << endl;
}

void Paladin::print() {
    cout << "Paladin: ";
    Hero::print();
}
