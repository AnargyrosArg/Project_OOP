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

void Party::useItem() {
    int heroIndex = 0, itemIndex = 0;
    for(int i=0; i<party.size(); i++){
        cout << i+1<<". ";
        party.at(i)->print();
    }
    cout << "Select Hero to use item" << endl;
    cin >> heroIndex;
    heroIndex--;
    if(heroIndex >= party.size()){
        cout << "No such hero" << endl;
        return;
    }
    cout << "Selected " << party.at(heroIndex)->getName() << endl;
    printInv();
    cout << "Select item to use" << endl;
    cin >> itemIndex;
    itemIndex--;
    if(itemIndex >= inventory.size()){
        cout << "No such item" << endl;
        return;
    }
    if(inventory.at(itemIndex)->getLevelReq()>party.at(heroIndex)->getLevel()){ //Item level check
        cout << "Level requirement not met"<<endl;
        return;
    }
    if (!(inventory.at(itemIndex)->isEquipped()))
    {
        inventory.at(itemIndex)->equip(party.at(heroIndex));
        if (inventory.at(itemIndex)->isConsumable())
            inventory.erase(inventory.begin() + itemIndex);
    }
    else cout << "Item is already equipped in party" << endl;
}