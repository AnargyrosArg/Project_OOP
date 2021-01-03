///
/// Created by Giann on 1/3/2021.
///

#include <vector>
#include "Block.h"

#ifndef UNTITLED1_COMMON_H
#define UNTITLED1_COMMON_H

class Common : public Block
{
    private:
        int encounterChance;
        vector <Monster*> monsters;

    public:
        Common(int level);
        ~Common() = default;
        void event(Party* party) override;
        void printMonsters() const;
        bool checkEndOfCombat(Party* party);
};


#endif //UNTITLED1_COMMON_H
