#ifndef BA_H
#define BA_H

#include "position.h"
#include "object.h"
#include "item.h"
#include "potion.h"

class BA : public Potion {
 public:
    BA(unique_ptr<Position> pos);
    BA(int price);
    void affectPlayer(Player &player, double magnify) override;
};

#endif
