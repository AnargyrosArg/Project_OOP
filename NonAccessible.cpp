//
// Created by anarg on 1/4/2021.
//

#include "NonAccessible.h"

void NonAccessible::event(Party *party) {
    cout << "Your party stumbles across an immovable obstacle!"<<endl;
    cout << "You can't possibly pass through here"<<endl;
    return;
}

void NonAccessible::printBlock() {
    cout << "[X]";
}
