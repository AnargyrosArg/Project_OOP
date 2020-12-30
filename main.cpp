#include <iostream>
#include "Weapon.h"
#include "Armour.h"
#include "Warrior.h"
#include "Paladin.h"
#include "Sorcerer.h"
#include "Spirit.h"
#include "Dragon.h"
#include "Exoskeleton.h"

using namespace std;

int main()
{
   Weapon testWeapon(50);
   cout << endl;
   Armour testArmour(50);
   cout << endl;

   Warrior warrior(50);
   warrior.levelUp();

   Paladin paladin(50);
   paladin.levelUp();

   Sorcerer sorcerer(50);
   sorcerer.levelUp();

   Spirit spirit(50);
   Dragon dragon(50);
   Exoskeleton exoskeleton(50);

   return 0;
}