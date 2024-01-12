#ifndef DROW_H
#define DROW_H

#include "object.h"
#include "character.h"
#include "player.h"


class Drow : public Player {
 public:
    Drow(int HP, int gold, unique_ptr<Position> pos);
    ~Drow() {}
};

#endif
