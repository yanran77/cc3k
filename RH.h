#ifndef RH_H
#define RH_H

#include "position.h"
#include "object.h"
#include "item.h"
#include "potion.h"

class RH : public Potion {
 public:
    RH(unique_ptr<Position> pos);
    RH(int price);
    void affectPlayer(Player &player, double magnify) override;
};

#endif
