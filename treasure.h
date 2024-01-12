#ifndef TREASURE_H
#define TREASURE_H

#include "item.h"

class Treasure : public Item {
 protected:
    int value;
 public:
    int getValue() const;
    virtual ~Treasure() = 0;
};

#endif
