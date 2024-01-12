#ifndef POTION_H
#define POTION_H

#include <string>
#include "item.h"
#include "position.h"
#include "object.h"
using namespace std;


class Potion : public Item {
    protected:
    int price;
 public:
    Potion() {}
    virtual ~Potion() = 0;
    virtual void affectPlayer(Player &player, double magnify) = 0;
    int getPrice() const;
};

#endif
