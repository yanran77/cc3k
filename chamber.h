#ifndef CHAMBER_H
#define CHAMBER_H

#include "position.h"

class Position;

class Chamber {
 public:
	int chamberID; 
	int rowStart;
	int rowEnd;
	int colStart;
	int colEnd;
	Chamber(int chamberID);
	bool checkRange(Position *pos);
	Position getPosition();
};

#endif
