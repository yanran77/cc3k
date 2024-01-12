#include "dwarf.h" 

Dwarf::Dwarf(unique_ptr<Position> pos) {
    this->type = "Dwarf";
    this->hp = 100;
    this->atk = 20;
    this->def = 30;
    this->pos = std::move(pos);
    this->isNeutral = false;
}
