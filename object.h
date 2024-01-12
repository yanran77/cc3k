#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <memory>
#include "position.h"

using namespace std;

class Object {
 protected:
  unique_ptr<Position> pos;
  string type;
 public:
  Object(): pos(make_unique<Position>()) {}
  virtual ~Object() = default; 
  void setPos(unique_ptr<Position> p);
  Position *getPos();
  string getType() const;
  bool playerWithinRange(const Position *playerPos);
};

#endif
