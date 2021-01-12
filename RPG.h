///
/// Created by Giann on 1/4/2021.
///

#ifndef RPG_H
#define RPG_H

#include "Grid.h"

class RPG
{
    private:
        Grid* grid;

    public:
        RPG();
        ~RPG();
        void play();
        void options();
        void move();
};


#endif //RPG_H
