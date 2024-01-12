#include "position.h"

using namespace std;

Position::Position(int x, int y): x{x}, y{y} {}

int Position::getX() const{ return x; }

int Position::getY() const{ return y; }

Position Position::newPos(string dir) const{
    Position p;
    if (dir == "no") {
		p.x = this->x;
		p.y = this->y - 1;
	} else if (dir == "so") {
		p.x = this->x;
		p.y = this->y + 1;
	} else if (dir == "we") {
		p.x = this->x - 1;
		p.y = this->y;
	} else if (dir == "ea") {
		p.x = this->x + 1;
		p.y = this->y;
	} else if (dir == "ne") {
		p.x = this->x + 1;
		p.y = this->y - 1;
	} else if (dir == "nw") {
		p.x = this->x - 1;
		p.y = this->y - 1;
	} else if (dir == "se") {
		p.x = this->x + 1;
		p.y = this->y + 1;
	} else if (dir == "sw") {
		p.x = this->x - 1;
		p.y = this->y + 1;
	}
	return p;
} 

void Position::setPos(int x, int y) {
	this->x = x;
	this->y = y;
}

bool Position::operator==(const Position &p) const{
	return x == p.x && y == p.y;
}

bool Position::operator!=(const Position &p) const{
	return x != p.x || y != p.y;
}

bool Position::operator<(const Position& p) const{
	if (y < p.y) {
		return true;
	} else if (y > p.y){
		return false;
	} else {
		if (x < p.x) {
			return true;
		} else {
			return false;
		}
	}
}
