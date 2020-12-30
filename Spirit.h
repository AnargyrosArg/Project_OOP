///
/// Created by Giann on 12/30/2020.
///

#ifndef SPIRIT_H
#define SPIRIT_H

#include "Monster.h"

class Spirit : public Monster
{
    public:
        Spirit(int lvl);
        ~Spirit() override;
};

#endif //SPIRIT_H
