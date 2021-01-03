#include <iostream>
#include "Weapon.h"
#include "Armour.h"
#include "Warrior.h"
#include "Paladin.h"
#include "Sorcerer.h"
#include "Spirit.h"
#include "Dragon.h"
#include "Exoskeleton.h"
#include "Party.h"
#include "HealthPotion.h"
#include "StrengthPotion.h"
#include "DexterityPotion.h"
#include "AgilityPotion.h"
#include "IceSpell.h"
#include "FireSpell.h"
#include "LightningSpell.h"
#include "Market.h"

using namespace std;

int main()
{
    srand(time(nullptr));
    Party party(new Warrior(30));
    party.setMoney(5200);
    Market market(25);
    market.event(&party);
    cout << ((120*25) + (rand() % (12*25)))<<endl;
    party.printInv();
//-------------------------------------------------------------------------
//    Warrior warrior(50);
//    HealthPotion hp(40);
//    AgilityPotion sp(50,50,3);
//    warrior.setHealth(50);
//    warrior.print();
//    sp.equip(&warrior);
//    hp.equip(&warrior);
//    warrior.print();
//    warrior.countTurn();
//    warrior.countTurn();
//    warrior.countTurn();
//    warrior.print();
//-------------------------------------------------------------------------
//   Weapon testWeapon(50);
//   cout << endl;
//   Armour testArmour(50);
//   cout << endl;
//
//   Warrior warrior(50);
//   warrior.levelUp();
//
//   Paladin paladin(50);
//   paladin.levelUp();
//
//   Sorcerer sorcerer(50);
//   sorcerer.levelUp();
//
//   Spirit spirit(50);
//   Dragon dragon(50);
//   Exoskeleton exoskeleton(50);
//----------------------------------------------------------------------------
/*    Warrior warrior(50);
    Sorcerer sorcerer(50);
    Party party(&warrior,&sorcerer);
    party.print();

    party.pickUp(new Weapon(50));
    party.pickUp(new Armour(50));
    party.pickUp(new Weapon(50));
    party.pickUp(new Armour(50));
    party.pickUp(new StrengthPotion(50));
    party.pickUp(new HealthPotion(50));
    party.printInv();

    party.useItem();
    party.useItem();
    party.useItem();
    party.print();

    Dragon dragon(50);
    Spirit spirit(50);

    for (int i=0; i<10; i++)
        warrior.attack(&dragon);

    for (int i=0; i<10; i++)
        sorcerer.attack(&spirit);

    for (int i=0; i<10; i++)
        dragon.attack(&warrior);

    for (int i=0; i<10; i++)
        spirit.attack(&sorcerer);

    dragon.print();
    spirit.print();
    party.print();

    party.printInv();
    party.useItem();
    party.useItem();

    cout << endl;*/
//----------------------------------------------------------------------------
//    Warrior warrior(50);
//    Sorcerer sorcerer(50);
//    Party party(&warrior, &sorcerer);
//
//    warrior.learnSpell(new IceSpell(50));
//    warrior.learnSpell(new IceSpell(20));
//    sorcerer.learnSpell(new FireSpell(50));
//    sorcerer.learnSpell(new LightningSpell(50));
//
//    party.print();
//
//    Dragon dragon(50);
//    Spirit spirit(50);
//
//    warrior.castSpell(&dragon);
//    warrior.castSpell(&spirit);
//
//    sorcerer.castSpell(&spirit);
//    sorcerer.castSpell(&dragon);
//
//    dragon.print();
//    spirit.print();
//
//    party.print();
//
//    cout << endl;
    return 0;

}