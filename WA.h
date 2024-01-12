#ifndef WA_H
#define WA_H

#include "position.h"
#include "object.h"
#include "item.h"
#include "potion.h"

class WA : public Potion {
 public:
    WA(unique_ptr<Position> pos);
    WA(int price);
    void affectPlayer(Player &player, double magnify) override;
};

#endif
