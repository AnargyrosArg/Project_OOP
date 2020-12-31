//
// Created by anarg on 12/31/2020.
//

#ifndef UNTITLED1_HEALTHPOTION_H
#define UNTITLED1_HEALTHPOTION_H
#include "Potion.h"

class HealthPotion: public Potion {
private:

public:
    HealthPotion(int level);
    ~HealthPotion();
    void use(Hero* hero);
};


#endif //UNTITLED1_HEALTHPOTION_H
