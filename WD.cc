#include "WD.h"

WD::WD(unique_ptr<Position> pos) {
    this->pos = std::move(pos);
    this->type = "WD";
}

WD::WD(int price) {
    this->type = "WD";
    this->price = price;
}

void WD::affectPlayer(Player &player, double magnify) {
    double newDef = player.getDef() - 5 * magnify;
    player.modifyDef(static_cast<int>(newDef));
}
