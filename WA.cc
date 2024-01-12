#include "WA.h"

WA::WA(unique_ptr<Position> pos) {
    this->pos = std::move(pos);
    this->type = "WA";
    this->price = 0;
}

WA::WA(int price) {
    this->type = "WA";
    this->price = price;
}

void WA::affectPlayer(Player &player, double magnify) {
    double newAtk = player.getAtk() - 5 * magnify;
    player.modifyAtk(static_cast<int>(newAtk));
}
