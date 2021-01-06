//
// Created by anarg on 1/4/2021.
//

#ifndef UNTITLED1_NONACCESSIBLE_H
#define UNTITLED1_NONACCESSIBLE_H
#include "Block.h"

class NonAccessible:public Block {
private:

public:
    bool isAccessible(){return false;}
    void event(Party* party);
    void printBlock();
};


#endif //UNTITLED1_NONACCESSIBLE_H
