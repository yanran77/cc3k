#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "object.h"
#include "character.h"
#include "enemy.h"
#include "orc.h"
#include "merchant.h"
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"

class EnemyFactory {
 public:
    static unique_ptr<Enemy> createEnemy(char &type, unique_ptr<Position> pos);
};

#endif
