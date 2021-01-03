///
/// Created by Giann on 1/2/2021.
///

#include "Spell.h"
#include <iostream>

/// CONSTRUCTOR
Spell::Spell(string name_, int cost_, int lvl, int dmg, int magicCost_, int pow)
: name(std::move(name_)), cost(cost_), levelReq(lvl), baseDamage(dmg), magicCost(magicCost_), power(pow) {}
