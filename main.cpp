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

using namespace std;

int main(){
    srand(time(NULL)); //keep this here
    Warrior warrior(40);
    HealthPotion hp(40);
    StrengthPotion sp(50,50,3);
    warrior.setHealth(50);
    warrior.print();
    sp.use(&warrior);
    hp.use(&warrior);
    warrior.print();
    warrior.countTurn();
    warrior.countTurn();
    warrior.countTurn();
    warrior.print();


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
//    Warrior warrior(50);
//    Sorcerer sorcerer(50);
//    Party party(&warrior,&sorcerer);
//    party.print();
//    party.pickUp(new Weapon(50));
//    party.pickUp(new Armour(50));
//    party.pickUp(new Weapon(50));
//    party.pickUp(new Armour(50));
//    party.printInv();
//    party.equip();
//    party.print();
   return 0;
}