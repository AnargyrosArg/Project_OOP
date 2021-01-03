///
/// Created by Giann on 1/2/2021.
///

#include "FireSpell.h"
#include "Utils.h"

/// CONSTRUCTOR
FireSpell::FireSpell(string name_, int cost_, int lvl, int dmg, int magicCost_, int pow)
        : Spell(std::move(name_), cost_, lvl, dmg, magicCost_, pow) {}

/// CONSTRUCTOR 2
FireSpell::FireSpell(int lvl)
        : Spell(getRandomName("../Names/Spells.txt"),
                ((120*lvl) + (rand() % (12*lvl))), lvl,lvl*14 + (rand() % lvl),
                lvl/2, lvl*2) {}

/// PRINT
void FireSpell::print() const
{
    cout << Spell::getName() << ": " << "Level " << Spell::getLevelReq() << " fire spell" << endl;
}

/// CAST
void FireSpell::cast(Monster *monster)
{
    int duration_ = 3;
    monster->addEffect(DEF_DEBUFF, Spell::getPower(), duration_);
    cout << "Monster " << monster->getName() << " receives a -" <<
         Spell::getPower() << " defence debuff for " << duration_ << " turns" << endl;
}