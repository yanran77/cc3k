#include "object.h"

using namespace std;

void Object::setPos(unique_ptr<Position> p) {
    this->pos = move(p);
}

Position *Object::getPos() {
	return this->pos.get();
}

bool Object::playerWithinRange(const Position *playerPos) {
    string dir[8] = {"ea", "we", "no", "so", "ne", "nw", "se", "sw"};
    for (int i = 0; i < 8; ++i) {
        if (getPos()->newPos(dir[i]) == *playerPos) { return true; }
    }
    return false;
}

string Object::getType() const {
	return this->type;
}
