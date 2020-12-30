///
/// Created by Giann on 12/30/2020.
///

#include "Monster.h"

#ifndef EXOSKELETON_H
#define EXOSKELETON_H

class Exoskeleton : public Monster
{
    public:
        Exoskeleton(int lvl);
        ~Exoskeleton() override;
};

#endif //EXOSKELETON_H
