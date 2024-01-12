#ifndef MERCHANT_H
#define MERCHANT_H

#include "enemy.h"
#include "object.h"
#include "character.h"
#include "itemfactory.h"
#include <iostream>
#include <map>

using namespace std;

class Merchant : public Enemy {
    map<unique_ptr<Potion>, int> store;
 public:
    Merchant(unique_ptr<Position> pos);
    ~Merchant() {}
    string sell(string p, Player &player);
    void printStore(Player &p) const;
    void printData(Player &p) const;
    void printFunction() const;
};

#endif
