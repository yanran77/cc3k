#include "normal.h"

Normal::Normal(unique_ptr<Position> pos) {
    this->pos = std::move(pos);
    this->type = "normal";
    this->value = 2;
} 

Normal::Normal(unique_ptr<Position> pos, int value) {
    this->pos = std::move(pos);
    this->type = "merchant hoard";
    this->value = value;
}
