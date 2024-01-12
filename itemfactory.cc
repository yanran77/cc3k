#include "itemfactory.h"
using namespace std;

// 0-RH,1-BA,2-BD,3-PH,4-WA,5-WD,6-normalgoldpile,7 - small hoard, 8 - merchant hoard, 9 - dragon hoard
unique_ptr<Item> ItemFactory::createItem(char &type, ItemType itemType, std::unique_ptr<Position> pos) {
    if (itemType == ItemType::Potion) {
            int typeIdx = rand() % 6;
            type = '0' + typeIdx;
            switch (typeIdx) {
                case 0: return make_unique<RH>(move(pos));
                case 1: return make_unique<BA>(move(pos));
                case 2: return make_unique<BD>(move(pos));
                case 3: return make_unique<PH>(move(pos));
                case 4: return make_unique<WA>(move(pos));
                case 5: return make_unique<WD>(move(pos));
            }
    } else if (itemType == ItemType::Treasure) {
        int typeIdx = rand() % 8;
           if (typeIdx < 5) {
            type = '6';
            return make_unique<Normal>(move(pos));
        } else if (typeIdx < 7) {
            type = '7';
            return make_unique<Small>(move(pos));
        } else {
            type = '9';
            return make_unique<DHoard>(move(pos));
        }
    }
}

unique_ptr<Potion> ItemFactory::createPotion(int price, int i) {
        if (i == 0) {
            return make_unique<RH>(price);
        } else if (i == 1) {
            return make_unique<BA>(price);
        } else if (i == 2) {
            return make_unique<BD>(price);
        } else if (i == 3) {
            return make_unique<PH>(price);
        } else if (i == 4) {
            return make_unique<WA>(price);
        } else { 
            return make_unique<WD>(price);
        }
}
