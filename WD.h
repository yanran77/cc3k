#ifndef WD_H
#define WD_H

#include "position.h"
#include "object.h"
#include "item.h"
#include "potion.h"

class WD : public Potion {
 public:
    WD(unique_ptr<Position> pos);
    WD(int price);
    void affectPlayer(Player &player, double magnify) override;
};

#endif
