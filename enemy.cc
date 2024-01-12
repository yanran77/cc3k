#include "enemy.h"

using namespace std;

string Enemy::attackPlayer(Player *opponent) {
    double amount;
    string combatInfo;

    string attacker = this->type;
    string defender = opponent->getType();
    int enemyAttack = this->atk;
    int pcDef = opponent->getDef();
    
    if (rand() % 2 == 0) {
        combatInfo = attacker + " missed attack. ";
        return combatInfo;
    }
    amount = (100.0 / (100.0 + pcDef)) * enemyAttack;
    opponent->modifyHp(opponent->getHp() - amount);

    combatInfo = attacker + " deals " + to_string(static_cast<int> (amount)) + " damage to PC. ";
    return combatInfo;
}

Position Enemy::move() {
    int dir = rand() % 8 + 1;
    if (dir == 1) {
        return this->pos->newPos("ea");
    } else if (dir == 2) {
        return this->pos->newPos("we");
    } else if (dir == 3) {
        return this->pos->newPos("no");
    } else if (dir == 4) {
        return this->pos->newPos("so");
    } else if (dir == 5) {
        return this->pos->newPos("ne");
    } else if (dir == 6) {
        return this->pos->newPos("nw");
    } else if (dir == 7) {
        return this->pos->newPos("sw");
    } else {
        return this->pos->newPos("se");
    }
}


bool Enemy::getIsNeutral() const{
    return this->isNeutral;
}

void Enemy::notNeutral() {
    this->isNeutral = false;
}
