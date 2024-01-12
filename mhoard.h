#ifndef MHOARD_H
#define MHOARD_H

#include "treasure.h"
#include "position.h"

using namespace std;


class MHoard : public Treasure {
 public:
    ~MHoard() {}
    MHoard(unique_ptr<Position> pos);
};

#endif
