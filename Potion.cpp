//
// Created by anarg on 12/30/2020.
//

#include "Potion.h"

int Potion::getEffect() {
    int effect;
    getType()==0 ? (effect=getLevelReq()*50) : (effect=getLevelReq()/2);
    return effect;
}
