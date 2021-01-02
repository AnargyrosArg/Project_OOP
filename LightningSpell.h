///
/// Created by Giann on 1/2/2021.
///

#include "Spell.h"

#ifndef LIGHTNINGSPELL_H
#define LIGHTNINGSPELL_H

class LightningSpell : public Spell
{
public:
    LightningSpell(string name_, int cost_, int lvl, int dmg, int magicCost_, int power);
    LightningSpell(int lvl);
    ~LightningSpell() = default;

    void cast(Monster* monster) override;
    void print() const override;
};


#endif //LIGHTNINGSPELL_H
