//
// Created by anarg on 1/3/2021.
//

#ifndef UNTITLED1_BLOCK_H
#define UNTITLED1_BLOCK_H
#include "Party.h"

class Block {
private:
public:
    virtual bool isAccessible(){return true;}
    virtual void event(Party* party)=0;
    virtual void printBlock()=0;
    virtual ~Block();
};


#endif //UNTITLED1_BLOCK_H
