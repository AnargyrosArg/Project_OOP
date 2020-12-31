///
/// Created by Giann on 12/30/2020.
///

#include "Hero.h"
#include "Utils.h"

using namespace std;

#ifndef WARRIOR_H
#define WARRIOR_H

class Warrior : public Hero
{
public:
    Warrior(int lvl);
    ~Warrior() override;
    void levelUp() override;
    void print();
};


#endif //WARRIOR_H
