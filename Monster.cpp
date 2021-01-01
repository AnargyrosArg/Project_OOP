///
/// Created by Giann on 12/30/2020.
///

#include "Monster.h"
#include "Hero.h"
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
    <<"---------------------------------"<< endl;
}

/// ATTACK
void Monster::attack(Hero* hero)
{

    bool dodged = (rand() % 100) < hero->getAgility()/4;

    if (!dodged)
    {
        int extraDamage = (rand() % baseDamage/8); /// do baseDamage + extraDamage between (-baseDamage/8, +baseDamage/8)
        if ((rand() % 100) < 50) extraDamage = extraDamage*(-1); /// 50% of the time monster deals less damage than the base
        int damageTotal = max(baseDamage + extraDamage, 0); /// add max(..., 0) so we never do negative damage
        hero->setHealth(hero->getHealth() - damageTotal);
        cout << endl << "Monster " << Entity::getName() << " attacks " << hero->getName() << " and deals " << damageTotal << " damage!";
    } else cout << endl << "Hero " << hero->getName() << " dodges " << Entity::getName() << "'s attack!";
}

