//
// Created by anarg on 1/3/2021.
//

#ifndef UNTITLED1_BLOCK_H
#define UNTITLED1_BLOCK_H
#include "Party.h"

class Block {
private:
public:
    virtual void event(Party* party)=0;
};


#endif //UNTITLED1_BLOCK_H
