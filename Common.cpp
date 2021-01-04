///
/// Created by Giann on 1/3/2021.
///

#include "Dragon.h"
#include "Spirit.h"
#include "Exoskeleton.h"
#include "Common.h"

/// CONSTRUCTOR
Common::Common(int level) : encounterChance(50) /// 100 % for now
{
    int monsterType;
    int monsterNumber = (rand() % 2) + 1;
    int monsterLevel = (level / monsterNumber); /// added level of all monsters = level of encounter

    for (int i=0; i<monsterNumber; i++)
    {
        monsterType = rand() % 3;

        switch(monsterType)
        {
            case 0: /// DRAGON
                monsters.push_back(new Dragon(monsterLevel));
                break;
            case 1: /// EXOSKELETON
                monsters.push_back(new Exoskeleton(monsterLevel));
                break;
            case 2: /// SPIRIT
                monsters.push_back(new Spirit(monsterLevel));
                break;
        }
    }
}

/// PRINT MONSTERS
void Common::printMonsters() const
{
    cout << endl;
    cout << "=============== MONSTER STATS ===============" << endl;
    for (int i=0; i<monsters.size(); i++)
        if (!monsters.at(i)->checkDead()) monsters.at(i)->print();
    cout << "=============================================" << endl << endl;
}

/// CHECK END OF COMBAT
bool Common::checkEndOfCombat(Party* party)
{
    bool partyDead = true, monstersDead = true;
    for (int i=0; i<party->getHeroes().size(); i++)
        if (!party->getHeroes().at(i)->checkDead()) partyDead = false;

    if (partyDead)
    {
        cout << "And thus, all of our heroes lay on the floor unconscious, their fate unknown." << endl <<
        "But the monsters had tasted sweet victory, and spared our heroes of their deserving oblivion." << endl <<
        "No doubt devastated by such a defeat, they wake up a while later." << endl <<
        "Wounded, both physically and mentally, they still had to keep going." << endl << endl;

        for (int i=0; i<party->getHeroes().size(); i++)
            party->getHeroes().at(i)->setHealth(party->getHeroes().at(i)->getMaxHealth()/2);
        return true;
    }

    for (int i=0; i<monsters.size(); i++)
        if (!monsters.at(i)->checkDead()) monstersDead = false;

    if (monstersDead)
    {
        cout << "And that was the end of this encounter, as our heroes managed to prevail in battle." << endl <<
        "They all shouted in excitement, filled with energy and joy, adrenaline still pumping through their veins." << endl <<
        "But battles such as these also give them the experience required to keep fighting even stronger foes!" << endl << endl;

        for (int i=0; i<party->getHeroes().size(); i++)
        {
            party->getHeroes().at(i)->setExperience(party->getHeroes().at(i)->getExperience() + monsters.size()*party->getLevel());
            if (party->getHeroes().at(i)->getExperience() > 100) party->getHeroes().at(i)->levelUp(); /// exp and level up

            party->setMoney(party->getMoney()+monsters.size()*party->getLevel()*2); /// money
        }
        return true;
    }
    return false;
}

/// EVENT (chance of combat)
void Common::event(Party *party)
{
    Hero* currentHero;
    Monster* currentMonster;
    int input, heroTargetIndex;
    bool combatFinished = false, j;
    double maxHp;

    if ((rand() % 100) < encounterChance)
    {
        cout << "It was calm at first. But over time, tension started to fill the air... Our heroes were not alone." << endl
        << "It was at this moment that they saw " << "the monsters creep out of the darkness. Prepare for battle!" << endl;

        while (!combatFinished)
        {
            /// player turn
            for (int currentHeroIndex = 0; currentHeroIndex < party->getHeroes().size(); currentHeroIndex++)
            {
                if (combatFinished) break;
                currentHero = party->getHeroes().at(currentHeroIndex);
                if (currentHero->checkDead()) continue;

                printMonsters();
                currentHero->print();
                cout << "It is " << currentHero->getName() << "'s time to act! What will they do?" << endl << endl;
                cout << "1. Attack" << endl << "2. Cast Spell" << endl << "3. Use Item" << endl;
                cin >> input;
                while ((input < 1) || (input > 3)) {
                    cout << "No such action" << endl << endl;
                    cout << "1. Attack" << endl << "2. Cast Spell" << endl << "3. Use Item" << endl;
                    cin >> input;
                }

                if (input != 3) /// ATTACK OR CAST SPELL
                {
                    for (int i = 0; i < monsters.size(); i++) {
                        if (input == 1) j = currentHero->attack(monsters.at(i)); /// returns false if monster is already dead
                        else j = currentHero->castSpell(monsters.at(i)); /// returns false if monster is already dead

                        combatFinished = checkEndOfCombat(party); if (combatFinished) break; /// check if we killed all monsters
                        if (j) break; /// if monster was not dead, break. If monster already dead, continue loop and target next monster
                    }
                } else party->useItem(currentHero); /// USE ITEM

                currentHero->countTurn(); /// count a turn for effects

                maxHp = (double) currentHero->getMaxHealth(); /// regen some hp
                currentHero->setHealth(currentHero->getHealth() + maxHp*0.02);
                if (currentHero->getHealth() > (int) maxHp) currentHero->setHealth((int) maxHp);
            }

            /// monster turn
            if (!combatFinished)
            {
                for (int monsterIndex = 0; monsterIndex < monsters.size(); monsterIndex++)
                {
                    currentMonster = monsters.at(monsterIndex);
                    if (currentMonster->checkDead()) continue;

                    heroTargetIndex = rand() % party->getHeroes().size(); /// choose random hero to attack
                    while (party->getHeroes().at(heroTargetIndex)->checkDead()) heroTargetIndex = rand() % party->getHeroes().size();
                    currentMonster->attack(party->getHeroes().at(heroTargetIndex));

                    combatFinished = checkEndOfCombat(party); if (combatFinished) break; /// check if all heroes have fainted

                    currentMonster->countTurn(); /// count turn

                    maxHp = (double) currentMonster->getMaxHealth(); /// regen some hp
                    currentMonster->setHealth(currentMonster->getHealth() + maxHp*0.02);
                    if (currentMonster->getHealth() > (int) maxHp) currentMonster->setHealth((int) maxHp);
                }
            }
        }

        party->print();

    } else cout << "A new place, but nothing of interest to be found. Onwards!" << endl;
}

void Common::printBlock() {
    cout << "[?]";
}
