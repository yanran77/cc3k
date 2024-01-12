#include "display.h"

using namespace std;

void Display::printPCInfo() const{
    cout << "Please choose your race:" << endl;
    cout << "(s) for Shade  (125 HP, 25 Atk, 25 Def)" << endl;
    cout << "(d) for Drow (150 HP, 25 Atk , 15 Def, all potions have their effect magnified by 1.5)" << endl;
    cout << "(v) for Vampire (50 HP, 25 Atk, 25 Def, gains 5 HP every successful attack and has no maximum HP)" << endl;
    cout << "(t) for Troll (120 HP, 25 Atk, 15 Def, regains 5 HP every turn; HP is capped at 120 HP)" << endl;
    cout << "(g) for Goblin (110 HP, 15 Atk, 20 Def, steals 5 gold from every slain enemy)" << endl;
}

void Display::printMap(Floor *floor) const {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 79; j++) {
            char cell = floor->map[i][j];
            if ((cell >= '0') && (cell < '6')) {
                cout << "\033[32m" << "P";
            } else if ((cell >= '6') && (cell <= '9')) {
                cout << "\033[33m" << "G";
            } else if ((cell == '@') || (cell == '/')){
                cout << "\033[34m" << cell;
            } else if ((cell == 'H') || (cell =='W') || (cell =='E') || (cell =='O') || (cell =='M') || (cell =='D') || (cell =='L')) {
                cout << "\033[31m" << cell;
            } else if ((cell == '#') || (cell == '-') || (cell == '|')) {
                cout << "\033[1;30m" << cell;
            } else {
                 cout << "\033[0m" << cell;
            }
        }
        std::cout << "\033[0m" << std::endl;
    }
}


void Display::printPanel(Floor *floor) const{
    Player *p = floor->player.get();
    cout << "Race: " << p->getType();
    cout << " Gold: " << p->getGold();
    cout << "                                        ";
    cout << "Floor " << to_string(floor->level) << endl;
    cout << "HP: " << p->getHp() << endl;
    cout << "Atk: " << p->getAtk() << endl;
    cout << "Def: " << p->getDef() << endl;
    cout << "Action: " << action << endl;
}

void Display::printLose() const{
    cout << endl;
    cout << endl;
    cout << "L       OOO   SSSSSS  EEEEEE" << endl;
    cout << "L     O     O S       E    " << endl;
    cout << "L     O     O SSSSSS  EEEEE" << endl;
    cout << "L     O     O      S  E    " << endl;
    cout << "LLLLL   OOO   SSSSSS  EEEEEE" << endl;
    cout << endl;
    cout << endl;
}
void Display::printWin() const{
    cout << endl;
    cout << endl;
    cout << "W     W IIIII N   N" << endl;
    cout << "W     W   I   NN  N" << endl;
    cout << "W  W  W   I   N N N" << endl;
    cout << " W W W    I   N  NN" << endl;
    cout << "  W W   IIIII N   N" << endl;
    cout << endl;
    cout << endl;
}

string Display::getAction() const {
    return action;
}

void Display::setAction(string ac) {
    action = ac;
}
