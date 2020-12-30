#include <iostream>
#include "Weapon.h"
#include "Armour.h"
#include "Warrior.h"


using namespace std;
int main()
{
   Weapon testWeapon(50);
   cout << endl;
   Armour testArmour(50);
   cout << endl;

   Warrior warrior(50);
   warrior.levelUp();

   return 0;
}