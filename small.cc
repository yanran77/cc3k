#include "small.h"

Small::Small(unique_ptr<Position> pos) {
    this->pos = std::move(pos);
    this->type = "small";
    this->value = 1;
} 
