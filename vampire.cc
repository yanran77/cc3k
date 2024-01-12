#include "vampire.h"

using namespace std;

Vampire::Vampire(int HP, int gold, unique_ptr<Position> pos) {
    this->type = "Vampire";
    this->pos = std::move(pos);
    this->hp = HP;
    this->atk = 25;
    this->def = 25;
    this->maxHp = -1;
    this->gold = gold;
    this->defaultAtk = 25;
    this->defaultDef = 25;
}

void Vampire::modifyHp(int newHp) {
    hp = newHp;
    if (hp > maxHp) {
        maxHp = hp;
    }
}
