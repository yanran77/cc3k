#include "BA.h"

BA::BA(unique_ptr<Position> pos) {
    this->pos = std::move(pos);
    this->type = "BA";
    this->price = 0;
}

BA::BA(int price) {
    this->type = "BA";
    this->price = price;
}

void BA::affectPlayer(Player &player, double magnify) {
    double newAtk = player.getAtk() + 5 * magnify;
    player.modifyAtk(static_cast<int>(newAtk));
}
