#include "PH.h"

PH::PH(unique_ptr<Position> pos) {
    this->pos = std::move(pos);
    this->type = "PH";
    this->price = 0;
}

PH::PH(int price) {
    this->type = "PH";
    this->price = price;
}

void PH::affectPlayer(Player &player, double magnify) {
    double newHP = player.getHp() - 10 * magnify;
    player.modifyHp(static_cast<int>(newHP));
}
