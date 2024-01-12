#include "dhoard.h"

DHoard::DHoard(unique_ptr<Position> pos) {
    this->pos = std::move(pos);
    this->type = "dragon hoard";
    this->value = 6;
    this->isGuard = true;
}

void DHoard::freeGuard() {
    this->isGuard = false;
}

bool DHoard::getIsGuard() {
    return this->isGuard;
}
