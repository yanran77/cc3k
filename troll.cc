#include "troll.h"

using namespace std;

Troll::Troll (int HP, int gold, unique_ptr<Position> pos) {
    this->type = "Troll";
    this->pos = std::move(pos);
    this->hp = HP;
    this->atk = 25;
    this->def = 15;
    this->maxHp = 120;
    this->gold = gold;
    this->defaultAtk = 25;
    this->defaultDef = 15;
}
