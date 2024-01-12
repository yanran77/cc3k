#include "mhoard.h"
 
MHoard::MHoard(unique_ptr<Position> pos) {
    this->pos = std::move(pos);
    this->type = "merchant hoard";
    this->value = 4;
}
