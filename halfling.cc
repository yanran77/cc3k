#include "halfling.h"


Halfling::Halfling(unique_ptr<Position> pos) {
    this->type = "Halfing";
    this->hp = 100;
    this->atk = 15;
    this->def = 20;
    this->pos = std::move(pos);
    this->isNeutral = false;
}
