///
/// Created by Giann on 12/30/2020.
///

#include "Hero.h"
#include "Utils.h"

using namespace std;

#ifndef PALADIN_H
#define PALADIN_H

class Paladin : public Hero
{
public:
    Paladin(int lvl);
    ~Paladin() override;
    void levelUp() override;
};


#endif //PALADIN_H
