#include "elf.h"

Elf::Elf(unique_ptr<Position> pos) {
    this->type = "Elf";
    this->hp = 140;
    this->atk = 30;
    this->def = 10;
    this->pos = std::move(pos);
    this->isNeutral = false;
}

string Elf::attackPlayer(Player *opponent) {
    double amount;
    int numAttack = 2;
    string combatInfo;
    // participator
    string attacker = this->type;
    string defender = opponent->getType();
    // Atk
    int enemyAttack = this->atk;
    // Def
    int pcDef = opponent->getDef();
    if (opponent->getType() == "Drow") { //elf attacks player twice, expect for drow
        numAttack = 1;
    }
    if (numAttack == 2) {
        combatInfo = attacker + " attacks twice: ";
    }
    for(int i = 0; i < numAttack; i++) {
        // injure
        if (rand() % 2 == 0) {
            combatInfo += attacker + " missed attack. ";
        } else {
            amount = (100.0 / (100.0 + pcDef)) * enemyAttack;
            opponent->modifyHp(opponent->getHp() - amount);
            combatInfo += attacker + " deals " + to_string(static_cast<int> (amount)) + " damage to PC. ";
        }
    }
    return combatInfo;
}
