//
// Created by anarg on 12/31/2020.
//

#include "Party.h"

Party::Party(Hero *hero1, Hero *hero2, Hero *hero3):money(0){
    party.push_back(hero1);
    party.push_back(hero2);
    party.push_back(hero3);
}

Party::Party(Hero *hero1, Hero *hero2):money(0){
    party.push_back(hero1);
    party.push_back(hero2);
}

Party::Party(Hero *hero) {
    party.push_back(hero);
}

void Party::print() {
    cout << endl;
    for(int i=0;i<party.size();i++){
        cout << i+1 << ". ";
        party.at(i)->print();
        cout <<endl;
    }
}

void Party::pickUp(Item *item) {
    inventory.push_back(item);
    cout << "Our group of adventurers comes across " << item->getName()
    << ". They nod at each other, and pick it up." << endl << endl;
}

void Party::printInv() {
    cout << "--------- Inventory ---------"<<endl;
    for(int i=0;i<inventory.size();i++){
        cout << i+1<<". ";
        inventory.at(i)->print();
        cout << endl;
    }
    cout << "Money: "<<getMoney()<<endl;
    cout << "-----------------------------"<<endl;
}

void Party::useItem(Hero* hero)
{
    int heroIndex = 0, itemIndex = 0;

    if (hero == nullptr) {
        for (int i = 0; i < party.size(); i++) {
            cout << i + 1 << ". ";
            party.at(i)->print();
        }
        cout << "Someone in the group wants to use an item..." << endl;
        cin >> heroIndex;
        heroIndex--;
        if (heroIndex >= party.size()) {
            cout << "No such hero" << endl;
            return;
        }
        cout << "That person is " << party.at(heroIndex)->getName() << endl;
        hero = party.at(heroIndex);
    }
    if (hero->checkDead()) {
        cout << "Can't use items on fainted heroes!";
        return;
    }

    printInv();
    cout << "Which item will he use?" << endl;
    cin >> itemIndex;
    itemIndex--;
    if(itemIndex >= inventory.size()){
        cout << "No such item" << endl;
        return;
    }
    if(inventory.at(itemIndex)->getLevelReq()>hero->getLevel()){ //Item level check
        cout << "Level requirement not met"<<endl;
        return;
    }
    if (!(inventory.at(itemIndex)->isEquipped()))
    {
        inventory.at(itemIndex)->equip(hero);
        if (inventory.at(itemIndex)->isConsumable())
            inventory.erase(inventory.begin() + itemIndex);
    }
    else cout << "Item is already equipped in party" << endl;
}

int Party::getLevel() {
    if(party.size()>0){
        return party.at(0)->getLevel();
    }
}
