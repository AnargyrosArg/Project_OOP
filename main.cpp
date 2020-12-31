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

using namespace std;

int main()
{
    srand(time(NULL)); //keep this here
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
    Warrior warrior(50);
    Sorcerer sorcerer(50);
    Party party(&warrior,&sorcerer);
    party.print();
    party.pickUp(new Weapon(50));
    party.pickUp(new Armour(50));
    party.pickUp(new Weapon(50));
    party.pickUp(new Armour(50));
    party.printInv();
    party.equip();
    party.print();
   return 0;
}