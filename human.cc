#include "human.h"

using namespace std;

Human::Human(unique_ptr<Position> pos) {
    this->type = "Human";
    this->hp = 140;
    this->atk = 20;
    this->def = 20;
    this->pos = std::move(pos);
    this->isNeutral = false;
}
