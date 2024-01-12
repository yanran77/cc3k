#include "BD.h"

BD::BD(unique_ptr<Position> pos) {
    this->pos = std::move(pos);
    this->type = "BD";
    this->price = 0;
}

BD::BD(int price) {
    this->type = "BD";
    this->price = price;
}

void BD::affectPlayer(Player &player, double magnify) {
    double newDef = player.getDef() + 5 * magnify;
    player.modifyDef(static_cast<int>(newDef));
}
