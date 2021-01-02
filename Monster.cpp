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
        cout << endl << "Filled with rage, monster " << Entity::getName() << " attacks "
        << hero->getName() << " and deals an impressive " << damageTotal << " damage!";
    } else cout << endl << "Hero " << hero->getName() << " dodges " << Entity::getName() << "'s attack! Inhuman reactions!";
}

/// ADD EFFECT (DEBUFF)
void Monster::addEffect(EffectType type, int power, int duration)
{
    Entity::getEffects().push_back(new Effects(type,power,duration));

    if(type == DMG_DEBUFF){
        setDamage(getDamage()-power);
        return;
    }
    if(type == DEF_DEBUFF){
        setDefence(getDefence()-power);
        return;
    }
    if(type == DODGE_DEBUFF){
        /// for a power of 100 (perhaps derived from a spell from a level 50 hero), this reduces dodge chance by 50%
        setDodge(getDodge()-(((double) power)/200.0));
        return;
    }
}

/// COUNT TURN
void Monster::countTurn() {
    for(int i=0;i<Entity::getEffects().size();i++){
        Entity::getEffects().at(i)->setDuration(Entity::getEffects().at(i)->getDuration()-1);
        if(Entity::getEffects().at(i)->getDuration()==0){
            if(Entity::getEffects().at(i)->getType()==DMG_DEBUFF){
                setDamage(getDamage()+Entity::getEffects().at(i)->getPower());
            }
            else if(Entity::getEffects().at(i)->getType()==DEF_DEBUFF){
                setDefence(getDefence()+Entity::getEffects().at(i)->getPower());
            }
            else if(Entity::getEffects().at(i)->getType()==DODGE_DEBUFF){
                setDodge(getDodge()+((double) Entity::getEffects().at(i)->getPower())/250.0);
            }
            Entity::getEffects().erase(Entity::getEffects().begin()+i);
        }
    }
}