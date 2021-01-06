///
/// Created by Giann on 1/4/2021.
///

#include "RPG.h"
#include "Warrior.h"
#include "Sorcerer.h"
#include "Paladin.h"
#include <vector>

/// CONSTRUCTOR
RPG::RPG()
{
    int peopleNumber, heroType;
    Hero* hero;
    vector <Hero*> heroes;

    cout << "Darkness. Moisture. Little oxygen. It was dead silent." << endl <<
    "That is, until some footsteps, echoed through the twisting hallways and expansive rooms" << endl <<
    "of the dungeon. A quiet sound, but amidst this silence, it seemed uncomfortably loud." << endl <<
    "It was a group of adventurers, each one seeking something different from this place." << endl <<
    "The number of people in the group was..." << endl;

    cin >> peopleNumber;
    while (peopleNumber < 1 || peopleNumber > 3)
    {
        if (peopleNumber > 3) {
            cout << "No more than 3..." << endl;
            cin >> peopleNumber;
        }

        if (peopleNumber < 1) {
            cout << "No less than 1..." << endl;
            cin >> peopleNumber;
        }
    }
    cout << peopleNumber << "! A small group, when compared to the task at hand." << endl;

    cout << "Their decisions over the span of their short lives led them right here." << endl <<
    "A true test of soul, body, and mind. Will they succeed, or will their journey come to a swift end?" << endl << endl;

    heroType = rand() % 3;
    for (int i=0; i<peopleNumber; i++)
    {
        if (heroType == 0) hero = new Warrior(8); /// warrior
        if (heroType == 1) hero = new Paladin(8); /// paladin
        if (heroType == 2) hero = new Sorcerer(8); /// sorcerer

        heroes.push_back(hero);
        heroType = rand() % 3;
    }

    int gridSize = 15;
    if (peopleNumber == 1) grid = new Grid(new Party(heroes.at(0)), gridSize, gridSize);
    if (peopleNumber == 2) grid = new Grid(new Party(heroes.at(0), heroes.at(1)), gridSize, gridSize);
    if (peopleNumber == 3) grid = new Grid(new Party(heroes.at(0), heroes.at(1), heroes.at(2)), gridSize, gridSize);

    options();
}

/// OPTIONS (aka playing the game)
void RPG::options()
{
    int input;
    bool gameEnd = false;

    cout << "The group considers its options..." << endl << endl;
    cout << "1. Show group stats" << endl;
    cout << "2. Check Inventory" << endl;
    cout << "3. Examine the dungeon Map" << endl;
    cout << "4. Use an item (equip / use potion)" << endl;
    cout << "5. Move (use WASD to move)" << endl;
    cout << "6. Live to fight another day (quit game)" << endl;

    cin >> input;
    cin.clear(); cin.ignore();
    while (input < 1 || input > 6)
    {
        cout << "On second thought, not an option at all." << endl;
        cin >> input;
        cin.clear(); cin.ignore();
    }

    switch(input)
    {
        case 1:
            grid->getParty()->print();
            break;
        case 2:
            grid->getParty()->printInv();
            break;
        case 3:
            grid->print();
            break;
        case 4:
            grid->getParty()->useItem();
            break;
        case 5:
            move();
            break;
        case 6:
            gameEnd = true;
            break;
    }

    cout << endl;

    if (!gameEnd) options();
    else cout << endl << "It seems our group has had enough adventuring for one day." << endl <<
    "They decide the best option is to leave this place." << endl <<
    "And so, the dungeon, ever changing, awaits for the next group of adventurers to challenge it. Patient as ever." << endl << endl;
}

/// MOVE
void RPG::move()
{
    char Move=0;
    grid->print();
    cout << endl << "The group starts to move. But in which direction? (use WASD to move)" << endl;

    cin >> Move;
    switch (Move)
    {
        case 'w':
            grid->moveUp();
            break;
        case 's':
            grid->moveDown();
            break;
        case 'd':
            grid->moveRight();
            break;
        case 'a':
            grid->moveLeft();
            break;
        default:
            cout << "Invalid input" << endl;
            break;
    }
    cin.clear();
    cout << endl;
}