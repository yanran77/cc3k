#ifndef ELF_H
#define ELF_H

#include "enemy.h"
#include "object.h"
#include "character.h"


class Elf : public Enemy {
 public:
    Elf(unique_ptr<Position> pos);
    ~Elf() {}
    string attackPlayer(Player *opponent) override;
};
    
#endif
