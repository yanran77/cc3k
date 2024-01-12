#ifndef GOBLIN_H
#define GOBLIN_H

#include "object.h"
#include "character.h"
#include "player.h"


class Goblin : public Player {
 public:
    ~Goblin() {}
    Goblin(int HP, int gold, unique_ptr<Position> pos);
};

#endif
