#ifndef NORMAL_H
#define NORMAL_H

#include "treasure.h"
#include "object.h"
#include "item.h"

using namespace std;

class Normal : public Treasure {
 public:
    Normal(unique_ptr<Position> pos);
    Normal(unique_ptr<Position> pos, int value);
    ~Normal() {}
};

#endif
