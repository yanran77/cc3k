#include "gameController.h"

using namespace std;

void GameController::start() {
    // print starting information
    // choose race
    char race;
    display->printPCInfo();
    while (1) {
        cin >> race;
        if(race == 's' || race == 'd' || race == 'v' || race == 'g' || race == 't') {
            break;
        } else if (race == 'q') {
            this->status = "quit";
            return;
        } else {
            cout << "Invalid race, choose again!" << endl;
        }
    }
    floor->initFloor(race);

    // laying out the map, spawn all elements in order
    display->setAction("Player character has spawned.");
    display->printMap(floor.get());
    display->printPanel(floor.get());
    

    // input
    string input;
    while(cin >> input) {
        display->setAction("");

        readCommand(input); //cope with commands

        if (this->status == "restart" || this->status == "quit") {
            break;
        }
        if (isValidInput && !floor->getIsFrozen()) {
            string msg = display->getAction();
            display->setAction(msg + floor->autoAttackPlayer());
            floor->randomMove();
        }
        
        if (floor->player->getType() == "Troll" && isValidInput) {
            if (floor->player->getHp() != floor->player->getMaxHp()) {
                floor->regainFive();
                string msg = display->getAction();
                display->setAction(msg + "Player regain hp. ");
            }
        }

        if (floor->player->getHp() <= 0) {
            floor->player->modifyHp(0);
            cout << "You died!" << endl;
            this->status = "die";
            display->printMap(floor.get());
            display->printPanel(floor.get());
            break;
        }
        if (floor->level == 6) {
            this->status = "win";
            break;
        }
        display->printMap(floor.get());
        display->printPanel(floor.get());
    }
}

void GameController::readCommand(string input) {
    isValidInput = true;
    if (input == "u") { // uses the potion indicated by the direction (e.g. no, so, ea).
        string dir;
        cin >> dir;
        if (validDirection(dir)) {
            string potionType = floor->usePotion(dir);
            if (potionType != "") {
                display->setAction("PC uses " + potionType + ". ");
            } else {
                display->setAction("No valid potion.");
                isValidInput = false;
                return;
            }
        } else {
            display->setAction("Invalid direction.");
            isValidInput = false;
            return;
        }

    } else if (validDirection(input)) { //player moves
        string ac = floor->movePlayer(input);
        display->setAction(ac);
        if (ac == "Invalid move.") {
            isValidInput = false;
            return;
        }

    } else if (input == "a") { //attack player indicated by direction
        string dir;
        cin >> dir;
        if (validDirection(dir)) {
            string note =floor->attackDir(dir);
            display->setAction(note);
            if (note == "Enemy not found.") {
                isValidInput = false;
                return;
            }
        } else {
            display->setAction("Invalid direction.");
            isValidInput = false;
            return;
        }

    } else if (input == "f") {
        this->floor->frozenEnemy();
        if (floor->getIsFrozen()) {
            display->setAction("Enemies are frozened. ");
        } else {
            display->setAction("Enemies are freed. ");

        }

    } else if (input == "b") {
        string dir;
        cin >> dir;
        string ac = this->floor->purchase(dir);
        display->setAction(ac);
        isValidInput = false;
        return;

    } else if (input == "r") {
        this->status = "restart";

    } else if (input == "q") {
        this->status = "quit";
    } else {
        //invalid input
        display->setAction("Invalid input, please try again. ");
        isValidInput = false;
        return;
    }
}

bool GameController::validDirection(string input) const {
    return ((input == "no") || (input == "so") || (input == "ea") || (input == "we") || (input == "ne") || (input == "nw") || (input == "se") || (input == "sw"));
}

Floor *GameController::getFloor() const{
    return floor.get();
}

Display *GameController::getDisplay() const {
    return display.get();
}

string GameController::getStatus() const {
    return status;
}
