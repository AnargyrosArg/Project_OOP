//
// Created by anarg on 12/31/2020.
//

#include "Party.h"

Party::Party(Hero *hero1, Hero *hero2, Hero *hero3) {
    party.push_back(hero1);
    party.push_back(hero2);
    party.push_back(hero3);
}

Party::Party(Hero *hero1, Hero *hero2) {
    party.push_back(hero1);
    party.push_back(hero2);
}

Party::Party(Hero *hero) {
    party.push_back(hero);
}

void Party::print() {
    for(int i=0;i<party.size();i++){
        cout << endl;
        party.at(i)->print();
        cout <<endl;
    }
}

void Party::pickUp(Item *item) {
    inventory.push_back(item);
}

void Party::printInv() {
    cout << "--------- Inventory ---------"<<endl;
    for(int i=0;i<inventory.size();i++){
        cout << i+1<<". ";
        inventory.at(i)->print();
        cout << endl;
    }
    cout << "-----------------------------"<<endl;
}

void Party::equip() {
    int heroindex=0,itemindex=0;
    for(int i=0;i<party.size();i++){
        cout << i+1<<". ";
        party.at(i)->print();
    }
    cout << "Select Hero to equip item to" << endl;
    cin >> heroindex;
    heroindex--;
    if(heroindex>=party.size()){
        cerr << "No such hero"<< endl;
        return;
    }
    cout << "Selected "<<party.at(heroindex)->getName()<<endl;
    printInv();
    cout << "Select item to equip" << endl;
    cin >> itemindex;
    itemindex--;
    if(itemindex>=inventory.size()){
        cerr << "No such item"<< endl;
        return;
    }

    if (!(inventory.at(itemindex)->isEquipped()))
        inventory.at(itemindex)->equip(party.at(heroindex));
    else cout << "Item is already equipped in party" << endl;
}