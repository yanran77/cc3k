#include "character.h"

using namespace std;
    
int Character::getAtk() const { return atk; }

int Character::getDef() const { return def; }

int Character::getHp() const { return hp; }

void Character::modifyAtk(int newAtk) {
    if (newAtk < 0) atk = 0; 
    else atk = newAtk;
}

void Character::modifyDef(int newDef) {
    if (newDef < 0) def = 0;
    else def = newDef; 
}

void Character::modifyHp(int newHp) { 
    if (newHp < 0) hp = 0;
    else hp = newHp;
}

Character::~Character() {}
