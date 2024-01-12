#ifndef TROLL_H
#define TROLL_H

#include "object.h"
#include "character.h"
#include "player.h"


class Troll : public Player {
 public:
    ~Troll() {}
    Troll(int HP, int gold, unique_ptr<Position> pos);
};

#endif
