//
// Created by anarg on 1/3/2021.
//

#include "Market.h"


Market::Market(int level) {
    for(int i=0;i<WEAPONS;i++) {
        items.push_back(new Weapon(level));
    }
    for(int i=0;i<ARMOURS;i++) {
        items.push_back(new Armour(level));
    }
    for(int i=0;i<POTIONS;i++) {
        int select=rand()%4;
        switch (select) {
            case 0:
                items.push_back(new StrengthPotion(level));
                break;
            case 1:
                items.push_back(new DexterityPotion(level));
                break;
            case 2:
                items.push_back(new AgilityPotion(level));
                break;
            case 3:
                items.push_back(new HealthPotion(level));
                break;
            default:
                items.push_back(new HealthPotion(level));
                return;
        }
    }
    for(int i=0;i<SPELLS;i++) {
        int select=rand()%3;
        switch (select) {
            case 0:
                spells.push_back(new FireSpell(level));
                break;
            case 1:
                spells.push_back(new LightningSpell(level));
                break;
            case 2:
                spells.push_back(new IceSpell(level));
                break;
            default:
                spells.push_back(new FireSpell(level));
                return;
        }
    }
}

void Market::printStock() {
    int i;
    cout << "---------- Market Stock ----------"<<endl;
    for(i=0;i<items.size();i++) {
        cout << i+1 <<". ";
        items.at(i)->print();
        cout << " / Cost: "<<items.at(i)->getCost();
        cout << endl;
    }
    for(int j=0;j<spells.size();i++,j++) {
        cout << i+1 <<". ";
        spells.at(j)->print();
        cout << " / Cost: "<< spells.at(j)->getCost()<<endl;
    }
}

void Market::event(Party *party) {
    int itemindex;
    printStock();
    cout << items.size()+spells.size()+1 << ". Sell Items"<<endl;
    cout << items.size()+spells.size()+2 << ". Exit market"<<endl;
    cout << "Choose action" <<endl;
    cout << "Money: " << party->getMoney() << endl;
    cin.clear();
    cin >> itemindex;
    --itemindex;
    if(itemindex==items.size()+spells.size()){
        Sell(party);
    }
    if(itemindex>=items.size()+spells.size() || itemindex < 0 ){
        cout << "The shopkeeper waves at you as you leave his store"<<endl;
        return;
    }
    if(purchase(itemindex, party)){
        removeFromStock(itemindex);
    }
    event(party);
}

bool Market::purchase(int itemindex,Party* party) {
    if(itemindex<items.size()) {
        if(party->getMoney()<items.at(itemindex)->getCost()) {
            cout << "Not enough money"<<endl;
            return false;
        }else{
            party->pickUp(items.at(itemindex));
            party->setMoney(party->getMoney()-items.at(itemindex)->getCost());
            return true;
        }
    }else{
        int spellindex=itemindex-items.size();
        if(party->getMoney()<spells.at(spellindex)->getCost()) {
            cout << "Not enough money"<<endl;
            return false;
        }
        int heroindex;
        cout <<"---------- Party ---------"<<endl;
        party->print();
        cout <<"--------------------------"<<endl;
        cout << "Select hero to teach spell to"<<endl;
        cin >> heroindex;
        --heroindex;
        if(heroindex<0||heroindex >= party->getHeroes().size()) {
            cout << "No such hero "<<endl;
            return false;
        }
        party->getHeroes().at(heroindex)->learnSpell(spells.at(spellindex));
        party->setMoney(party->getMoney()-spells.at(spellindex)->getCost());
        return true;
    }

//    if(party->getMoney()>=items[itemindex]->getCost()){
//        party->setMoney(party->getMoney()-items[itemindex]->getCost());
//        party->pickUp(items[itemindex]);
//    }else{
//        cout << "Not enough money!"<<endl;
//    }
}

void Market::removeFromStock(int itemindex) {
    if(itemindex<items.size()){
        items.erase(items.begin()+itemindex);
    }else {
        int spellindex=itemindex-items.size();
        spells.erase(spells.begin()+spellindex);
    }
}

void Market::printBlock() {
    cout << "[M]";
}

void Market::Sell(Party *party) {
    party->printInv();
    int itemindex;
    cout << party->getItemCount()+1<< ". Cancel"<<endl;
    cout << "Choose action";
    cin >> itemindex;
    itemindex--;
    if(itemindex>=party->getItemCount() || itemindex<0){
        event(party);
        return;
    }else if(!party->getInv().at(itemindex)->isEquipped()){
        party->setMoney(party->getMoney()+(party->getInv().at(itemindex)->getCost())/2);
        party->getInv().erase(party->getInv().begin()+itemindex);
        event(party);
        return;
    }

}
