#include "playerfactory.h"

unique_ptr<Player> PlayerFactory::createPlayer(char race, unique_ptr<Position> pos) {
    if (race == 's') {
        return make_unique<Shade>(125, 0, std::move(pos));
    } else if (race == 'd') {
        return make_unique<Drow>(150, 0, std::move(pos));
    } else if (race == 'v') {
        return make_unique<Vampire>(50, 0, std::move(pos));
    } else if (race == 't') {
        return make_unique<Troll>(120, 0, std::move(pos));
    } else {
        return make_unique<Goblin>(110, 0, std::move(pos));
    }
}
