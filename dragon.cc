#include "dragon.h"

Dragon::Dragon(unique_ptr<Position> pos, DHoard *dhoard) {
    this->type = "Dragon";
    this->hp = 150;
    this->atk = 20;
    this->def = 20;
    this->pos = std::move(pos);
    this->isNeutral = true;
    this->dhoard = dhoard;
}

void Dragon::freeHoard() {
    dhoard->freeGuard();
}

DHoard *Dragon::getDHoard() const {
    return this->dhoard;
}

void Dragon::setNeutral() {
    this->isNeutral = true;
}
