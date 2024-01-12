#ifndef BD_H
#define BD_H

#include "position.h"
#include "object.h"
#include "item.h"
#include "potion.h"

class BD : public Potion {
 public:
    BD(unique_ptr<Position> pos);
    BD(int price);
    void affectPlayer(Player &player, double magnify) override;
};

#endif
