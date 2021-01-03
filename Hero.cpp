///
/// Created by Giann on 12/30/2020.
///

#include "Hero.h"
#include <iostream>

/// CONSTRUCTOR
Hero::Hero(string name_, int lvl, int hp, int magic_, int str, int dex, int agil)
: Entity(std::move(name_), lvl, hp), maxMagic(magic_), magic(maxMagic), strength(str), dexterity(dex), agility(agil), money(0), experience(0)
,armour(nullptr),weapon1(nullptr),weapon2(nullptr){}

/// DESTRUCTOR
Hero::~Hero() {}

/// SET ARMOUR
void Hero::setArmour(Armour* armour_) {
    if(getLevel() >= armour_->getLevelReq()) {
        if (armour != nullptr) armour->setEquipped(false);
        armour = armour_;
        armour->setEquipped(true);
        cout << Entity::getName() << " feels more confident in their armour, which goes by the name "<<armour->getName()<<endl;
        return;
    }else{
        cout << "Level requirement for "<<armour->getName()<<" not met"<<endl;
        return;
    }

}

/// EQUIP WEAPON
void Hero::equipWeapon(Weapon* weapon)
{
    if (weapon->getLevelReq()<=getLevel()) {
        if (weapon->isTwoHanded()) {
            if (weapon1 != nullptr) weapon1->setEquipped(false);
            if (weapon2 != nullptr) weapon2->setEquipped(false);
            weapon1=weapon;
            weapon2= nullptr;
            weapon1->setEquipped(true);
            cout << Entity::getName() << " now holds "<<weapon->getName()<<" steadily, in both hands"<<endl;
            return;
        }
        else {
            if (weapon1 == nullptr) {
                weapon1=weapon;
                weapon1->setEquipped(true);
                cout << Entity::getName() << " equipped " << weapon->getName() << " in their one hand" << endl;
                return;
            }
            if (weapon2 == nullptr) {
                weapon2 = weapon;
                weapon2->setEquipped(true);
                cout << Entity::getName() << " grabs " << weapon->getName() << " with his hand" << endl;
                return;
            }
            if (weapon1 != nullptr && weapon2 != nullptr) {
                weapon1->setEquipped(false);
                weapon1 = weapon;
                weapon1->setEquipped(true);
                cout << "After careful consideration, " << Entity::getName() << " swaps "<< weapon1->getName() << " for " << weapon->getName() << endl;
                return;
            }
        }
    } else cout << "Level requirement for "<<weapon->getName()<<" not met"<<endl;
}

/// PRINT
void Hero::print() {
    cout << Entity::getName()<<endl
    << "Level: "<<getLevel() <<endl
    << "Health:" <<getHealth()<<"/"<<getMaxHealth()<<endl
    <<"Magic: "<<getMagic() <<"/"<< getMaxMagic()<<endl
    << "--------------Stats--------------" << endl <<
    " Str: "<< Hero::getStrength()  <<
    " Dex: " << Hero::getDexterity() <<
    " Agil: " << Hero::getAgility()<<endl
    <<"---------------------------------"<< endl;
    if(weapon1!= nullptr){
        cout << "Weapon 1: "<<weapon1->getName()<<endl;
    }
    if(weapon2!= nullptr){
        cout << "Weapon 2: "<<weapon2->getName()<<endl;
    }
    if(armour!=nullptr){
        cout << "Armour: "<<armour->getName() <<endl;
    }
    if (!spells.empty()) printSpells();
    cout << endl;
}

/// PRINT SPELLS
void Hero::printSpells()
{
    cout << endl << "--------- Spells ---------" << endl;
    for(int i=0; i<spells.size(); i++)
    {
        cout << i+1 << ". ";
        spells.at(i)->print();
    }
    cout << "--------------------------" << endl;
}

/// LEARN SPELL
void Hero::learnSpell(Spell *spell) {
    spells.push_back(spell);
    cout << "Through practice, dedication and determination, " << Entity::getName() << " has mastered the "
    << spell->getName() << endl;
}

/// ADD EFFECT
void Hero::addEffect(EffectType type,int power, int duration) {
    Entity::getEffects().push_back(new Effects(type,power,duration));
    if(type==STRENGTH){
        setStrength(getStrength()+power);
        return;
    }
    if(type==DEXTERITY){
        setDexterity(getDexterity()+power);
        return;
    }
    if(type==AGILITY){
        setAgility(getAgility()+power);
        return;
    }
}

/// COUNT TURN
void Hero::countTurn() {
    for(int i=0;i<Entity::getEffects().size();i++){
        Entity::getEffects().at(i)->setDuration(Entity::getEffects().at(i)->getDuration()-1);
        if(Entity::getEffects().at(i)->getDuration()==0){
            if(Entity::getEffects().at(i)->getType()==STRENGTH){
                setStrength(getStrength()-Entity::getEffects().at(i)->getPower());
            }
            else if(Entity::getEffects().at(i)->getType()==DEXTERITY){
                setDexterity(getDexterity()-Entity::getEffects().at(i)->getPower());
            }
            else if(Entity::getEffects().at(i)->getType()==AGILITY){
                setAgility(getAgility()-Entity::getEffects().at(i)->getPower());
            }
            Entity::getEffects().erase(Entity::getEffects().begin()+i);
        }
    }
}

/// ATTACK
void Hero::attack(Monster* monster)
{
    if (weapon1 != nullptr)
    {
        bool dodged = (rand() % 100) < (monster->getDodge())*100;

        if (!dodged)
        {
            int dmg = max((weapon1->getDamage() + strength - monster->getDefence()), 0); /// add max(..., 0) so we never do negative damage
            monster->setHealth(monster->getHealth() - dmg);
            cout << endl << "Hero " << Entity::getName() << " strikes " << monster->getName() << " dealing " << dmg << " damage! Ouch.";
        } else cout << endl << "Monster " << monster->getName() << " dodges " << Entity::getName() << "'s attack, mocking his lack of accuracy";
    }
    else cout << endl << Entity::getName() << " attempts to attack unarmed! A foolish attempt.";

    if (weapon2 != nullptr)
    {
        bool dodged = (rand() % 100) < (monster->getDodge())*100;

        if (!dodged)
        {
            int dmg = max((weapon2->getDamage() + strength - monster->getDefence()), 0);
            monster->setHealth(monster->getHealth() - dmg);
            cout << endl << "Hero " << Entity::getName() << " attacks " << monster->getName() << " again and deals " << dmg << " damage!";
        } else cout << endl << "With swift reflexes, monster " << monster->getName() << " dodges " << Entity::getName() << "'s second attack!";
    }
}

/// CAST SPELL
void Hero::castSpell(Monster *monster)
{
    int spellIndex;

    printSpells();
    cout << "Within a split second, " << Entity::getName() << " decides to cast..." << endl;
    cin >> spellIndex;
    spellIndex--;

    if(spellIndex >= spells.size()) {
        cout << "No such spell" << endl;
        return;
    }

    Spell* spell = spells.at(spellIndex);
    string heroName = Entity::getName();
    string spellName = spell->getName();
    int manaCost = spell->getMagicCost();

    if (magic < manaCost)
    {
        cout << endl << "Hero " << heroName << " acts hastily, disregarding his lack of mana required to cast " << spellName << "!";
        return;
    }

    bool dodged = (rand() % 100) < (monster->getDodge())*100;
    magic -= manaCost;

    if (!dodged)
    {
        int dmg = max((spell->getDamage() + dexterity + (rand() % (spell->getLevelReq()*10)) - monster->getDefence()), 0);
        monster->setHealth(monster->getHealth() - dmg);
        cout << endl << "Hero " << heroName << " casts " << spellName << " targeting " <<
        monster->getName() << " and deals a whopping " << dmg << " damage!" << endl;
        spell->cast(monster); /// apply debuff
    } else cout << endl << "Monster " << monster->getName() << " dodges " << heroName << "'s " << spellName << " gracefully!";
}