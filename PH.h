#ifndef PH_H
#define PH_H

#include "position.h"
#include "object.h"
#include "item.h"
#include "potion.h"

class PH : public Potion {
  public:
    PH(unique_ptr<Position> pos);
    PH(int price);
    void affectPlayer(Player &player, double magnify) override;
};

#endif
