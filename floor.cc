#include "floor.h"

using namespace std;

Floor::Floor(): player(std::make_unique<Player>()) {
    for (int i = 0; i < 6; ++i){
        this->isPotionKnown[i] = false;
    }
}

void Floor::initMap(string file) {
    ifstream in{file};
	string str;
	for (int i = 0; i < 25; i++) {
		getline(in, str);
		for (int j = 0; j < 79; j++) {
			map[i][j] = str[j];
            defaultMap[i][j] = str[j];
		}
	}
}

void Floor::redrawMap() {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 79; j++) {
            map[i][j] = defaultMap[i][j];
        }
    }
}

// destructor
Floor::~Floor() {
    clearFloor();
    chambers.clear();
}

void Floor::initFloor(char race) {
    int playerChamberID;
    int dragonNum = 0;
    generateChamber();
    spawnPlayer(race, playerChamberID);
    spawnStair(playerChamberID);
    spawnItems(dragonNum);
    spawnEnemies(dragonNum);
}

void Floor::clearFloor() {
    enemies.clear();
    treasures.clear();
    potions.clear();
}

void Floor::initNext() {
    bool isPreNeutral = this->isMNeutral;
    redrawMap();
    clearFloor();
    int playerChamberID;
    int dragonNum = 0;
    generateChamber();
    playerChamberID = 1 + rand() % 5;
    Position pos = chambers[playerChamberID - 1]->getPosition();
    int x = pos.getX();
    int y = pos.getY();
    unique_ptr<Position> p = make_unique<Position>(x, y);
    player->modifyAtk(player->getDefaultAtk());
    player->modifyDef(player->getDefaultDef());
    player->setPos(move(p));
    map[pos.getY()][pos.getX()] = '@';
    spawnStair(playerChamberID);
    spawnItems(dragonNum);
    spawnEnemies(dragonNum);
    // merchant hostile from previous floor
    if (!isPreNeutral) {
        isMNeutral = false;
        for (size_t k = 0; k < enemies.size(); k++) {
            if (enemies[k]->getType() == "Merchant") {
                enemies[k]->notNeutral();
            }
       }
    }
}

// spawn chamber
void Floor::generateChamber() {
	for(int i = 0; i < 5; i++) {
		unique_ptr<Chamber> c = make_unique<Chamber>(i + 1);
		chambers.push_back(move(c));
	}
}

// spawn player
void Floor::spawnPlayer(char race, int &playerChamberID) {
    playerChamberID = rand() % 5 + 1;
    Position pos = chambers[playerChamberID - 1]->getPosition();
    int x = pos.getX();
    int y = pos.getY();
    unique_ptr<Position> p = make_unique<Position>(x, y);
    this->player = PlayerFactory::createPlayer(race, move(p));
    map[pos.getY()][pos.getX()] = '@';
}

// spawn stair
void Floor::spawnStair(int &playerChamberID) {
    int stairChamberID = rand() % 4 + 1;
    if (stairChamberID < playerChamberID) {
        Position pos = chambers[stairChamberID - 1]->getPosition();
        map[pos.getY()][pos.getX()] = '/';
    } else {
        Position pos = chambers[stairChamberID]->getPosition();
        map[pos.getY()][pos.getX()] = '/';
    }
}

// spawn items
void Floor::spawnItems(int &dragonNum) {
    int chamberID;
    Position pos;
    char type;
    
    //spawn potions
    for (int i = 0; i < 10; i++) {
        chamberID = 1 + rand() % 5;
        pos = getValidPos(chamberID);
        int x = pos.getX();
        int y = pos.getY();
        unique_ptr<Position> p = make_unique<Position>(x, y);
        unique_ptr<Item> itemPtr = ItemFactory::createItem(type, ItemType::Potion, move(p));
        potions.push_back(unique_ptr<Potion>(static_cast<Potion*>(itemPtr.release())));
        //potions.push_back(ItemFactory::createItem(type, ItemType::Potion, move(p)));
        map[pos.getY()][pos.getX()] = type;
    }

    //spawn treasures
    for (int i = 0; i < 10; i++) {
        chamberID = 1 + rand() % 5;
        pos = getValidPos(chamberID);
        int x = pos.getX();
        int y = pos.getY();
        unique_ptr<Position> p = make_unique<Position>(x, y);
        unique_ptr<Item> itemPtr = ItemFactory::createItem(type, ItemType::Treasure, move(p));
        treasures.push_back(unique_ptr<Treasure>(static_cast<Treasure *>(itemPtr.release())));
        //treasures.push_back(ItemFactory::createTreasure(type, move(p)));
        map[pos.getY()][pos.getX()] = type;
    
        if (type == '9') { //if the generated treasure is dragon hoard 
            DHoard *dh = static_cast <DHoard *>(treasures.back().get());
            Position dragonPos = generateDragonPos(&pos);
            int x = dragonPos.getX();
            int y = dragonPos.getY();
            unique_ptr<Position> p = make_unique<Position>(x, y);
            enemies.push_back(make_unique<Dragon> (move(p), dh));
            map[dragonPos.getY()][dragonPos.getX()] = 'D';
            dragonNum++;
        }
    }
}

// spawn dragon
Position Floor::generateDragonPos(Position *dhPos) {
    Position pos;
	while (1) {
		int idx = rand() % 8;
		string dir[8] = {"ea", "we", "no", "so", "ne", "nw", "sw", "se"};
		pos = dhPos->newPos(dir[idx]);
        if ((map[pos.getY()][pos.getX()] == '.')) break;
	}
	return pos;
}

// spawn enemies
void Floor::spawnEnemies(int &dragonNum) {
    int num = 20 - dragonNum;
    int chamberID;
    Position pos;
    char type;
    for (int i = 0; i < num; i++) {
        chamberID = 1 + rand() % 5;
        pos = getValidPos(chamberID);
        int x = pos.getX();
        int y = pos.getY();
        unique_ptr<Position> p = make_unique<Position>(x, y);
        enemies.push_back(EnemyFactory::createEnemy(type, move(p)));
        map[pos.getY()][pos.getX()] = type;
    }
}

string Floor::usePotion(string dir) {
    Position *curPos = player->getPos();
    Position newPos = curPos->newPos(dir);
    int x = newPos.getX();
    int y = newPos.getY();
    unique_ptr<Position> p = make_unique<Position>(x, y);
    double magnify = 1.0;
    // drow can modify potion effect by 1.5
    if (player->getType() == "Drow") {
        magnify = 1.5;
    }
    char cell = map[newPos.getY()][newPos.getX()];
    
    if (cell == '0') {
        for (size_t i = 0; i < potions.size(); i++) {
            if (potions[i]->getType() == "RH") {
                potions[i]->affectPlayer(*player, magnify);
                break;
            }
        }
        isPotionKnown[0] = true;
    } else if (cell == '1') {
        for (size_t i = 0; i < potions.size(); i++) {
            if (potions[i]->getType() == "BA") {
                potions[i]->affectPlayer(*player, magnify);
                break;
            }
        }
        isPotionKnown[1] = true;
    } else if (cell == '2') {
        for (size_t i = 0; i < potions.size(); i++) {
            if (potions[i]->getType() == "BD") {
                potions[i]->affectPlayer(*player, magnify);
                break;
            }
        }
        isPotionKnown[2] = true;
    } else if (cell == '3') {
        for (size_t i = 0; i < potions.size(); i++) {
            if (potions[i]->getType() == "PH") {
                potions[i]->affectPlayer(*player, magnify);
                break;
            }
        }
        isPotionKnown[3] = true;
    } else if (cell == '4') {
        for (size_t i = 0; i < potions.size(); i++) {
            if (potions[i]->getType() == "WA") {
                potions[i]->affectPlayer(*player, magnify);
                break;
            }
        }
        isPotionKnown[4] = true;
    } else if (cell == '5') {
        for (size_t i = 0; i < potions.size(); i++) {
            if (potions[i]->getType() == "WD") {
                potions[i]->affectPlayer(*player, magnify);
                break;
            }
        }
        isPotionKnown[5] = true;
    } else {
        return "";
    }
    for (size_t i = 0; i < potions.size(); i++) {
        if (*potions[i]->getPos() == newPos) {
            string type = potions[i]->getType();
            potions.erase(potions.begin() + i);
            map[newPos.getY()][newPos.getX()] = '@';
            map[curPos->getY()][curPos->getX()] = defaultMap[curPos->getY()][curPos->getX()];
            player->setPos(move(p));
            return type;
        }
    }
    return "";
} 

string Floor::purchase(string dir) {
    string msg;
    string potionKind;
    Merchant *targetMerchant;
    Position *curPos = player->getPos();
    Position newPos = curPos->newPos(dir);
    char cell = map[newPos.getY()][newPos.getX()];
    if (cell == 'M') {
        string action;
        for (size_t i = 0; i < enemies.size(); i++) {
            if (*enemies[i]->getPos() == newPos) {
                targetMerchant = static_cast<Merchant *> (enemies[i].get());
                break;
            }
        }
        // print the function of each potion
        targetMerchant->printFunction();
        // open store
        while (1) {
            targetMerchant->printStore(*player);
            cin >> potionKind;
            if (potionKind == "exit") {
                msg = "You leave the store. ";
                break;
            }
            string purchaseState = targetMerchant->sell(potionKind, *player);
            if (purchaseState == "error purchasing") {
                cout << "Invalid potion, try again! " << endl;
            }
        }
        msg = "trade with the Merchant.";
    } else {
        msg = "There is no merchant around! ";
    }

    return msg;
}


string Floor::attackDir(string dir) {
    Position *curPos = player->getPos();
    Position newPos = curPos->newPos(dir);
    int x = newPos.getX();
    int y = newPos.getY();
    unique_ptr<Position> p = make_unique<Position>(x, y);
    char cell = map[newPos.getY()][newPos.getX()];
    if (cell == 'H' || cell == 'W' || cell == 'E' || cell == 'O' || cell == 'M' || cell == 'D' || cell == 'L') {
        string action;
        for (size_t i = 0; i < enemies.size(); i++) {
            if (*enemies[i]->getPos() == newPos) {
                action = player->attackEnemy(enemies[i].get());
                //merchants become hostile
                if (enemies[i]->getType() == "Merchant") {
                    if (this->isMNeutral) {
                        this->isMNeutral = false;
                        for (size_t k = 0; k < enemies.size(); k++) {
                            if (enemies[k]->getType() == "Merchant") {
                                enemies[k]->notNeutral();
                            }
                        }
                    }
                }
                if (enemies[i]->getHp() <= 0) { //If this enemy dies...
                    action += "You have slained an enmey! ";
                    if (player->getType() == "Goblin") { //if the PC is goblin, steal 5 golds
                        player->pickGold(5);
                    }
                    string enemyType = enemies[i]->getType();
                    if (enemyType == "Dragon") {
                        //free the dragon hoard
                        Dragon *dragon = static_cast<Dragon *>(enemies[i].get());
                        dragon->freeHoard();
                        map[newPos.getY()][newPos.getX()] = defaultMap[newPos.getY()][newPos.getX()];

                    } else if (enemyType == "Merchant") {
                        //add a merchant hoard
                        auto mhoard = make_unique<MHoard> (move(p));
                        treasures.push_back(move(mhoard));
                        map[newPos.getY()][newPos.getX()] = '8';

                    } else if (enemyType == "Human") {
                        //add two normal
                        auto hHoard = make_unique<Normal>(move(p), 4);
                        treasures.push_back(move(hHoard));
                        map[newPos.getY()][newPos.getX()] = '6';

                    } else {
                        //drop either a small pile or normal pile of gold. 
                        //This gold is immediately added to the player character’s total.
                        int random = rand() % 2;
                        if (random == 0) {
                            player->pickGold(1);
                        } else {
                            player->pickGold(2);
                        }
                        map[newPos.getY()][newPos.getX()] = defaultMap[newPos.getY()][newPos.getX()];
                    }
                    enemies.erase(enemies.begin() + i);
                }
            }
        }
        if (player->getType() == "Vampire" && cell == 'W') { //vampire lose 5 hp when it attacks dwarf rather than gain
            player->modifyHp(player->getHp() - 5);
            action += "You are allergic to dwarves and lose 5 HP rather than gain. ";

        } else if (player->getType() == "Vampire" && cell == 'L') { //vampire gains 5 hp when attacking enemies except for dwarf
            regainFive();
            
        } else if (player->getType() == "Vampire" && action != "You missed!") { // vampire gains 5 hp when attacking halfling successfully
            regainFive();
        }
        return action;
    } else {
        return "Enemy not found.";
    }
}

void Floor::regainFive() {
    player->modifyHp(player->getHp() + 5);
}

string Floor::direction(string dir) {
    if (dir == "we") {
        return "West";
    } else if (dir == "no") {
        return "North";
    } else if (dir == "so") {
        return "South";
    } else if (dir == "ea") {
        return "East";
    } else if (dir == "ne") {
        return "Northeast";
    } else if (dir == "nw") {
        return "Northwest";
    } else if (dir == "se") {
        return "Southeast";
    } else if (dir == "sw") {
        return "Southwest";
    } else {
        return "Invalide dirction.";
    }
}

string Floor::movePlayer(string dir) {
    string msg;
    Position *curPos = player->getPos();
    Position newPos = player->getPos()->newPos(dir);
    int x = newPos.getX();
    int y = newPos.getY();
    unique_ptr<Position> p = make_unique<Position>(x, y);
    char cell = map[newPos.getY()][newPos.getX()];

    //check if there are potions surrounded
    for (size_t i = 0; i < potions.size(); i++) {
            if (potions[i]->playerWithinRange(p.get())) {
                msg += seePotion(potions[i].get());
            }
    }
    
	if (cell == '6' || cell == '7' || cell == '8') { //small or normal hoard or merchant hoard
        msg += "PC moves to " + direction(dir) + ". ";
        msg += pickGold(newPos);
        map[newPos.getY()][newPos.getX()] = '@';
        map[curPos->getY()][curPos->getX()] = defaultMap[curPos->getY()][curPos->getX()];
        player->setPos(move(p));

    } else if (cell == '9') { //dragon hoard
        //find that dragon hoard
        for (size_t i = 0; i < treasures.size(); i++) {
            if (*treasures[i]->getPos() == newPos) {
                DHoard *dh = static_cast <DHoard *>(treasures[i].get());
                if (!dh->getIsGuard()) { //if this hoard is not guarded
                    msg += "PC moves to " + direction(dir) + ". ";
                    map[newPos.getY()][newPos.getX()] = '@';
                    map[curPos->getY()][curPos->getX()] = defaultMap[curPos->getY()][curPos->getX()];
                    player->setPos(move(p));
                    msg += pickGold(newPos);
                } else { //dragon will attack player
                    msg += "There is a guarded dragon hoard. Invalid move! ";
                } 
            }
        }
    
    } else if (cell == '/') {
        if (level != 6) {
            initNext();
            msg += "You enter Floor " + to_string(++level);
            if (level == 6) return "You win!";
            else return msg;
        }  
        
    } else if (cell == '.' || cell == '+' || cell == '#') {
        map[newPos.getY()][newPos.getX()] = '@';
        map[curPos->getY()][curPos->getX()] = defaultMap[curPos->getY()][curPos->getX()];
        msg += "PC moves " + direction(dir) + ". ";
        player->setPos(move(p));

    } else {
        msg = "Invalid move.";
    }

   return msg;
}

string Floor::pickGold(Position p) {
    for (size_t i = 0; i < treasures.size(); i++) {
        if (*treasures[i]->getPos() == p) {
            int amount = treasures[i]->getValue();
            player->pickGold(amount);
            treasures.erase(treasures.begin() + i);
            return "PC picked " + to_string(amount) + " golds. ";
        }
    }
    return "";
}

string Floor::seePotion(Potion *p) {
    string type = p->getType();
    if (type == "RH"){
        if (isPotionKnown[0]){
            return "You see a Restore Health potion. ";
        }
    } else if (type == "BA"){
        if (isPotionKnown[1]){
            return "You see a Boost potion. ";
        }
   } else if (type == "BD"){
        if (isPotionKnown[2]){
            return "You see a Boost Defense potion. ";
        }    
   } else if (type == "PH"){
        if (isPotionKnown[3]){
            return "You see a Poison Health potion. ";
        }    
   } else if (type == "WA"){
        if (isPotionKnown[4]){
            return "You see a Wound Attack potion. ";
        }    
   } else if (type == "WD"){
        if (isPotionKnown[5]){
            return "You see a Wound Defense potion. ";
        }   
   } 
    return "You see an unknown potion. ";   
}

//random movement
void Floor::randomMove() {
    sortEnemies();
    for (size_t i = 0; i < enemies.size(); i++) {
        if(enemies[i]->getType() == "Dragon") {
            continue;
        }

        if (!enemies[i]->playerWithinRange(player->getPos())) {
            Position newPos;
            Position *curPos = enemies[i]->getPos();
            int curX = curPos->getX();
            int curY = curPos->getY();
            int newX;
            int newY;
            while (1) {
                newPos = enemies[i]->move();
                newX = newPos.getX();
                newY = newPos.getY();
                unique_ptr<Position> p = make_unique<Position>(newX, newY);
                char c = map[newPos.getY()][newPos.getX()];
                if (c == '.') {
                    enemies[i]->setPos(move(p));
                    break;
                }
            }
            map[newY][newX] = map[curY][curX];
            map[curY][curX] = '.';
        }
    }
}

// use insertion sort to sort enemies so that they attack player in a 'line-by-line' fashion
void Floor::sortEnemies() {
    int i, j;
    for (i = 1; i < enemies.size(); i++) {
        auto key = move(enemies[i]);
        j = i - 1;
        while (j >= 0 && *key->getPos() < *enemies[j]->getPos()) {
            enemies[j + 1] = move(enemies[j]);
            j = j - 1;
        }
        enemies[j + 1] = move(key);
    }
}

string Floor::autoAttackPlayer() {
    string autoAttackLog = "";

    //if player is near dragon hoards, change their guardian dragons to hostile
    for (size_t i = 0; i < treasures.size(); i++) {
        if (treasures[i]->getType() == "dragon hoard") {
            DHoard *dh = static_cast <DHoard *>(treasures[i].get());
            if (dh->playerWithinRange(player->getPos())) {
                 for (size_t i = 0; i < enemies.size(); i++) {
                        if (enemies[i]->getType() == "Dragon") {
                            if (*static_cast <Dragon *>(enemies[i].get())->getDHoard()->getPos() == *dh->getPos()) {
                                Dragon *d = static_cast <Dragon *> (enemies[i].get());
                                d->notNeutral();
                            }
                            
                        }
                    }
            }
        }
    }
    
    for (size_t i = 0; i < enemies.size(); i++) {
        if (enemies[i]->getType() == "Dragon") {
            Dragon *d = static_cast <Dragon *>(enemies[i].get());
            if (d->playerWithinRange(player->getPos())) d->notNeutral(); //if player is near any dragon, change dragon to hostile
            if (!d->getIsNeutral()) {
                autoAttackLog += d->attackPlayer(player.get());
                d->setNeutral();
                break;
            }
        }
        if (enemies[i]->playerWithinRange(player->getPos())) {
            if (!enemies[i]->getIsNeutral()) {
                autoAttackLog += enemies[i]->attackPlayer(player.get());
            }
        }
    }
    return autoAttackLog;
}

// get a unoccupied position within certain chamber for an object to spawn
Position Floor::getValidPos(int chamberID) {
    Position pos;
    while (1) {
        pos = chambers[chamberID - 1]->getPosition();
        if (map[pos.getY()][pos.getX()] == '.') {
            break;
        }
    }
    return pos;
}


void Floor::frozenEnemy() {
    if(isFrozen) {
        isFrozen = false;
    } else {
        isFrozen = true;
    }
}

bool Floor::getIsFrozen() const{
    return isFrozen;
}
