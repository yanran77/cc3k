#ifndef HALFLING_H
#define HALFLING_H

#include "enemy.h"
#include "object.h"
#include "character.h"


class Halfling : public Enemy {
 public:
    Halfling(unique_ptr<Position> pos);
    ~Halfling() {}
};

#endif
