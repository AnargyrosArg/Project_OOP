///
/// Created by Giann on 12/30/2020.
///

#include "Hero.h"
#include "Utils.h"

using namespace std;

#ifndef SORCERER_H
#define SORCERER_H

class Sorcerer : public Hero
{
public:
    Sorcerer(int lvl);
    ~Sorcerer() override;
    void levelUp() override;
    void print();
};


#endif //SORCERER_H
