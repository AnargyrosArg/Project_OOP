///
/// Created by Giann on 12/30/2020.
///

#include "Monster.h"

#ifndef DRAGON_H
#define DRAGON_H

class Dragon : public Monster
{
    public:
        Dragon(int lvl);
        ~Dragon() override;

        void print() const override;
};

#endif //DRAGON_H
