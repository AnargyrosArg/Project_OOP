///
/// Created by Giann on 12/30/2020.
///

#include "Sorcerer.h"
#include "IceSpell.h"
#include "FireSpell.h"
#include "LightningSpell.h"

using namespace std;

/// CONSTRUCTOR
Sorcerer::Sorcerer(int lvl) : Hero(getRandomName("./Names/Names.txt"), lvl, lvl*6, lvl*4, lvl, lvl*4, lvl*3)
{
    cout << "An adventurer of the group is a Sorcerer named " << Entity::getName() << ". Stats:" << endl << "Hp: " << Entity::getMaxHealth()
    << endl << "Mag: " << Hero::getMaxMagic() << endl << "Str: " << Hero::getStrength() << endl
    << "Dex: " << Hero::getDexterity() << endl << "Agil: " << Hero::getAgility() << endl << endl;

    /// starter spell / weapon
    int spellType = rand() % 3;
    if (spellType == 0) Hero::learnSpell(new IceSpell(lvl));
    if (spellType == 1) Hero::learnSpell(new FireSpell(lvl));
    if (spellType == 2) Hero::learnSpell(new LightningSpell(lvl));
    Hero::equipWeapon(new Weapon(lvl/2));
    cout << endl;
}

/// DESTRUCTOR
Sorcerer::~Sorcerer()
{
 //   cout << "Destroyed Sorcerer named " << Entity::getName() << ". Stats:" << endl << "Mag: " << Hero::getMaxMagic() << endl << "Str: "
   //      << Hero::getStrength() << endl << "Dex: " << Hero::getDexterity() << endl << "Agil: " << Hero::getAgility() << endl << endl;
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
