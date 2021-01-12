///
/// Created by Giann on 12/30/2020.
///

#include "Warrior.h"

using namespace std;

/// CONSTRUCTOR
Warrior::Warrior(int lvl) : Hero(getRandomName("./Names/Names.txt"), lvl, lvl*10, lvl*2, lvl*3, lvl, lvl*3)
{
    cout << "In the group there is a warrior named " << Entity::getName() << ". Stats:" << endl << "Hp: " << Entity::getMaxHealth()
    << endl << "Mag: " << Hero::getMaxMagic() << endl << "Str: " << Hero::getStrength() << endl
    << "Dex: " << Hero::getDexterity() << endl << "Agil: " << Hero::getAgility() << endl << endl;

    /// starter weapon
    Hero::equipWeapon(new Weapon(lvl));
    cout << endl;
}

/// DESTRUCTOR
Warrior::~Warrior()
{
  //  cout << "Destroyed Warrior named " << Entity::getName() << ". Stats:" << endl << "Mag: " << Hero::getMaxMagic() << endl << "Str: "
//    << Hero::getStrength() << endl << "Dex: " << Hero::getDexterity() << endl << "Agil: " << Hero::getAgility() << endl << endl;
}

/// LEVEL UP
void Warrior::levelUp()
{
    Entity::setLevel(Entity::getLevel()+1); /// level up!
    Hero::setExperience(0); /// reset exp
    Hero::setAgility(Hero::getAgility() + 3); /// warrior is proficient in agility
    Hero::setStrength(Hero::getStrength() + 3); /// warrior is proficient in strength
    Hero::setDexterity(Hero::getDexterity() + 1); /// warrior is not proficient in dexterity
    Hero::setMaxMagic(Hero::getMaxMagic() + 2); /// max magic increase
    Entity::setMaxHealth(Entity::getMaxHealth()+10); /// max health increase

    cout << "Warrior named " << Entity::getName() << " leveled up to level " << Entity::getLevel() << "!" << endl << endl;
}

void Warrior::print() {
    cout << "Warrior: ";
    Hero::print();
}
