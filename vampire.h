#ifndef VAMPIER_H
#define VAMPIER_H

#include "object.h"
#include "character.h"
#include "player.h"


class Vampire : public Player {
 public:
    Vampire(int HP, int gold, unique_ptr<Position> pos);
    void modifyHp(int newHp) override;
    ~Vampire() {}
};

#endif
