#ifndef DWARF_H
#define DWARF_H

#include "enemy.h"
#include "object.h"
#include "character.h"


class Dwarf : public Enemy {
 public:
    Dwarf(unique_ptr<Position> pos);
    ~Dwarf() {}
};

#endif
