#include "enemyfactory.h"

unique_ptr<Enemy> EnemyFactory::createEnemy(char &type, unique_ptr<Position> pos) {
    int typeIdx = rand() % 18 + 1;
    if (typeIdx <= 4) {
        type = 'H';
        return make_unique<Human> (std::move(pos));
    } else if (typeIdx <= 7) {
        type = 'W';
        return make_unique<Dwarf> (std::move(pos));
    } else if (typeIdx <= 12) {
        type = 'L';
        return make_unique<Halfling> (std::move(pos));
    } else if (typeIdx <= 14) {
        type = 'E';
        return make_unique<Elf> (std::move(pos));
    } else if (typeIdx <= 16) {
        type = 'O';
        return make_unique<Orc> (std::move(pos));
    } else {
        type = 'M';
        return make_unique<Merchant> (std::move(pos));
    }
}
