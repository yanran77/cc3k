#ifndef SHADE_H
#define SHADE_H

#include "object.h"
#include "character.h"
#include "player.h"

using namespace std;

class Shade : public Player {
 public:
    Shade(int HP, int gold, unique_ptr<Position> pos);
    ~Shade() {}
};

#endif
