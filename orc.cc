#include "orc.h"

using namespace std;

Orc::Orc(unique_ptr<Position> pos) {
    this->type = "Orc";
    this->hp = 180;
    this->atk = 30;
    this->def = 25;
    this->pos = std::move(pos);
    this->isNeutral = false;
}

string Orc::attackPlayer(Player *opponent) {
    double magnify = 1.0;
    if(opponent->getType() == "Goblin") {
        magnify = 1.5;
    }
    string combatInfo;
    // participator
    string attacker = this->type;
    string defender = opponent->getType();
    // Atk
    int enemyAttack = this->atk;
    // Def
    int pcDef = opponent->getDef();
    // injure
    if (rand() % 2 == 0) {
        combatInfo = attacker + " missed attack. ";
        return combatInfo;
    }
    double amount = ((100.0 / (100.0 + pcDef)) * enemyAttack) * magnify;
    opponent->modifyHp(opponent->getHp() - amount);
    
    if (opponent->getType() == "Goblin") {
        combatInfo = attacker + " deals " + to_string(static_cast<int>(amount)) + " damage to PC, with 50% more damage. ";
    } else {
        combatInfo = attacker + " deals " + to_string(static_cast<int>(amount)) + " damage to PC. ";
    }
    
    return combatInfo;
}
