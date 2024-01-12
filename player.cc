#include "player.h"

using namespace std;

int Player::getGold() const { return gold; }

int Player::getMaxHp() const { return maxHp; }

void Player::pickGold(int amount)  { this->gold += amount; }

void Player::spendGold(int amount) { this->gold -= amount; }

string Player::attackEnemy(Enemy *opponent) {
    if (opponent->getType() == "Halfing") {
        int i = rand() % 2;
        if (i == 0) {
            return "You missed! ";
        }
    }
    double amount;
    string combatInfo;
    // participator
    string defender = opponent->getType();
    // Atk
    int pcAttack = getAtk();
    // Def
    int oppoDef = opponent->getDef();
    // injure
    amount = (100.0 / (100.0 + oppoDef)) * pcAttack;
    opponent->modifyHp(opponent->getHp() - amount);
    combatInfo = "PC deals " + to_string(static_cast<int> (amount)) + " damage to " + defender + " (" + to_string(opponent->getHp()) + " HP). ";

    return combatInfo;
}

int Player::getDefaultAtk() {
    return defaultAtk;
}
int Player::getDefaultDef() {
    return defaultDef;
}

void Player::modifyMaxHp(int newMax) {
    this->maxHp = newMax;
}

void Player::modifyHp(int newHp) {
    if (newHp < 0) {
        this->hp = 0;
    } else if (newHp <= maxHp) {
        this->hp= newHp;
    } else {
        this->hp= maxHp;
    }
}
