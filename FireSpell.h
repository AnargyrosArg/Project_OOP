///
/// Created by Giann on 1/2/2021.
///

#include "Spell.h"

#ifndef FIRESPELL_H
#define FIRESPELL_H

class FireSpell : public Spell
{
public:
    FireSpell(string name_, int cost_, int lvl, int dmg, int magicCost_, int power);
    FireSpell(int lvl);
    ~FireSpell() = default;

    void cast(Monster* monster) override;
    void print() const override;
};


#endif //FIRESPELL_H
