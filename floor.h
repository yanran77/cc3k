#ifndef FLOOR_H
#define FLOOR_H

#include <string>
#include <vector>
#include "enemy.h"
#include "potion.h"
#include "treasure.h"
#include "object.h"
#include "player.h"
#include "small.h"
#include "shade.h"
#include "troll.h"
#include "drow.h"
#include "vampire.h"
#include "goblin.h"
#include "position.h"
#include "chamber.h"
#include "character.h"
#include "item.h"
#include "orc.h"
#include "merchant.h"
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "dragon.h"
#include "mhoard.h"
#include "playerfactory.h"
#include "itemfactory.h"
#include "enemyfactory.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <memory>

using namespace std;

class Position;

class Floor {
    char defaultMap[25][79];
    vector<unique_ptr<Enemy>> enemies;
    vector<unique_ptr<Potion>> potions;
    bool isPotionKnown[6];
    vector<unique_ptr<Treasure>> treasures;
    vector<unique_ptr<Chamber>> chambers;
    bool isFrozen = false;

 public:
    Floor();
    ~Floor();
    unique_ptr<Player> player;
    bool isMNeutral = true;
    int level = 1;
    char map[25][79];
    void initMap(string file);
    void redrawMap(); //redraw the map when enter a new floor
    void initFloor(char race); //spawn player, stair, items, enemies
    void clearFloor();
    void initNext();
    void generateChamber();
    void spawnPlayer(char race, int &playerChamberID);
    void spawnStair(int &playerChamberID);
    void spawnItems(int &dragonNum);
    void spawnEnemies(int &dragonNum);
    string movePlayer(string dir);
    string pickGold(Position p);
    string seePotion(Potion *p);
    string usePotion(string dir);
    string purchase(string dir); // new ---------------------store---------------------
    void randomMove();
    void sortEnemies();
    string attackDir(string dir);
    string autoAttackPlayer();
    Position getValidPos(int chamberID);
    Position generateDragonPos(Position *dhPos);
    void regainFive();
    void frozenEnemy();
    bool getIsFrozen() const;
    string direction(string dir);
};

#endif
