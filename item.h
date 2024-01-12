#ifndef ITEM_H
#define ITEM_H

#include "character.h"
#include "object.h"
#include "player.h"

using namespace std;

class Item : public Object{
 public:
    virtual ~Item() = 0;
};

#endif
