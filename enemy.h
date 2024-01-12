#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"
#include "character.h"
#include <cstdlib>
#include <iostream>

using namespace std;

class Player;

class Enemy : public Character {
 protected:
   bool isNeutral;
 public:
   virtual string attackPlayer(Player *opponent);
   bool getIsNeutral() const;
   Position move();
   void notNeutral();
};

#endif
