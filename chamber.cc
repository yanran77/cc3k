#include "chamber.h"
using namespace std;

Chamber::Chamber(int chamberID) {
	if (chamberID == 1) {
		this->chamberID = 1;
		this->rowStart = 3;
		this->rowEnd = 6;
		this->colStart = 3;
		this->colEnd = 28;
	} else if (chamberID == 2) {
		this->chamberID = 2;
		this->rowStart = 15;
		this->rowEnd = 21;
		this->colStart = 4;
		this->colEnd = 24;
	} else if (chamberID == 3) {
		this->chamberID = 3;
		this->rowStart = 3;
		this->rowEnd = 12;
		this->colStart = 39;
		this->colEnd = 75;
	} else if (chamberID == 4) {
		this->chamberID = 4;
		this->rowStart = 10;
		this->rowEnd = 12;
		this->colStart = 38;
		this->colEnd = 49;
	} else if (chamberID == 5) {
		this->chamberID = 5;
		this->rowStart = 16;
		this->rowEnd = 21;
		this->colStart = 37;
		this->colEnd = 75;
	}
}

bool Chamber::checkRange(Position *pos) {
	int x = pos->getX();
	int y = pos->getY();
	
	if (chamberID == 1 || chamberID == 2 || chamberID == 4) {
		return (x >= colStart && x <= colEnd && y >= rowStart && y <= rowEnd);

	} else if (chamberID == 3) {
		if (x >= colStart && y >= rowStart && x <= 60 && y <= 6) {
			return true;
		} else if (x == 61 && y >= 3 && y <= 12) {
			return true;
		} else if (x >= 62 && y >= 5 && x <= 69 && y <= 12) {
			return true;
		} else if (x >= 70 && y >= 6 && x <= 72 && y <= 12) {
			return true;
		} else if (x >= 73 && y >= 7 && x <= 75 && y <= 12) {
			return true;
		}
		
	} else if (chamberID == 5) {
		if (x >= 37 && y >= 19 && x <= 64 && y <= 21) {
			return true;
		} else if (x >= 65 && y >= 16 && x <= 75 && y <= 21) {
			return true;
		}
	}
	return false;
}

Position Chamber::getPosition() {
	Position pos;
	while (1) {
		int row = rand() % (rowEnd - rowStart + 1) + rowStart;
		int col = rand() % (colEnd - colStart + 1) + colStart;
		pos.setPos(col, row);
		if (checkRange(&pos)) break;
	}
	return pos;
}
