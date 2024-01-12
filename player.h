#ifndef PLAYER_H
#define PLAYER_H
#include "object.h"
#include "character.h"
#include "enemy.h"
#include "position.h"
#include <cstdlib>

class Enemy;

class Player : public Character {
 protected:
    int maxHp = 0;
    int gold = 0;
    int defaultAtk = 0;
    int defaultDef = 0;
 public:
    Player() {}
    int getGold() const;
    int getMaxHp() const;
    string attackEnemy(Enemy *opponent);
    void pickGold(int amount);
    void spendGold(int amount);
    int getDefaultAtk();
    int getDefaultDef();
    void modifyMaxHp(int newMax);
    virtual void modifyHp(int newHp) override;
};

#endif
