///
/// Created by Giann on 12/30/2020.
///

#include "Hero.h"
#include <iostream>

/// CONSTRUCTOR
Hero::Hero(string name_, int lvl, int hp, int magic_, int str, int dex, int agil)
: Entity(std::move(name_), lvl, hp), maxMagic(magic_), magic(maxMagic), strength(str), dexterity(dex), agility(agil), money(0), experience(0) {}

/// DESTRUCTOR
Hero::~Hero() {}