///
/// Created by Giann on 1/2/2021.
///

#include "Spell.h"

#ifndef ICESPELL_H
#define ICESPELL_H

class IceSpell : public Spell
{
    public:
        IceSpell(string name_, int cost_, int lvl, int dmg, int magicCost_, int power);
        IceSpell(int lvl);
        ~IceSpell() = default;

        void cast(Monster* monster) override;
        void print() const override;
};


#endif //ICESPELL_H
