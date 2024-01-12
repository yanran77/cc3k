#ifndef POSITION_H
#define POSITION_H

#include <string>
using namespace std;

class Position {
    int x;
    int y;
 public:
    Position(int x, int y);
    Position() {}
    ~Position() {}
	void setPos(int x, int y);
    Position newPos(string dir) const;
    int getX() const;
    int getY() const;
    bool operator==(const Position& p) const;
    bool operator!=(const Position& p) const;
    bool operator<(const Position& p) const;
};

#endif
