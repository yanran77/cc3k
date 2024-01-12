#ifndef CHARACTER_H
#define CHARACTER_H

#include "object.h"

using namespace std;

class Character : public Object {
 protected:
    int hp = 0;
    int atk = 0;
    int def = 0;
 public:
    // accessor
    int getAtk() const;
    int getDef() const;
    int getHp() const;

    // mutator
    void modifyAtk(int newAtk);
    void modifyDef(int newDef);
    virtual void modifyHp(int newHp);
    virtual ~Character() = 0;
};

#endif
