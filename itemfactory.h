#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "potion.h"
#include "item.h"
#include "treasure.h"
#include "small.h"
#include "dhoard.h"
#include "normal.h"
#include "RH.h"
#include "BA.h"
#include "BD.h"
#include "PH.h"
#include "WA.h"
#include "WD.h"

enum class ItemType {
    Potion,
    Treasure
};

class ItemFactory {
 public:
    ItemFactory();
    ~ItemFactory() {}
    static unique_ptr<Item> createItem(char &type, ItemType itemType, std::unique_ptr<Position> pos);
    static unique_ptr<Potion> createPotion(int price, int typeIdx);
};

#endif
