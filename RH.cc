#include "RH.h"

RH::RH(unique_ptr<Position> pos) {
    this->pos = std::move(pos);
    this->type = "RH";
    this->price = 0;
}

RH::RH(int price) {
    this->type = "RH";
    this->price = price;
}

void RH::affectPlayer(Player &player, double magnify) {
    double newHP = player.getHp() + 10 * magnify;
    player.modifyHp(static_cast<int>(newHP));
}
