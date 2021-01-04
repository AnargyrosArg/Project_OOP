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
#include "Common.h"
#include "Grid.h"

using namespace std;

int main()
{
    srand(time(nullptr));
    Party party(new Warrior(5));
    Grid grid(&party,5,5);
    party.pickUp(new Weapon(5));
    party.useItem();
    char Move=0;
    grid.print();
    cout << endl;
    while(Move!=-1){ //wasd to move
        cin >> Move;
        switch (Move) {
            case 'w':
                grid.moveUp();
                break;
            case 's':
                grid.moveDown();
                break;
            case 'd':
                grid.moveRight();
                break;
            case 'a':
                grid.moveLeft();
                break;
        }
        cin.clear();
    }
    cout << endl;
    return 0;

}