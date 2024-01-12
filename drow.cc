#include "drow.h"

using namespace std;

Drow::Drow(int HP, int gold, unique_ptr<Position> pos) {
    this->type = "Drow";
    this->pos = std::move(pos);
    this->hp = HP;
    this->atk = 25;
    this->def = 15;
    this->maxHp = 150;
    this->gold = gold;
    this->defaultAtk = 25;
    this->defaultDef = 15;
}
