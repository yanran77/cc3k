#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include "gameController.h"


using namespace std;


int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "please enter a file" << std::endl;
        return 1;
    }

    srand(time(NULL));
    string file = argv[1];
    
    while(true) {
        GameController gc;
        gc.getFloor()->initMap(file);

        // start a round of game
        gc.start();

        //4 ways that quit or restart the game
        if (gc.getStatus() == "quit") {
            gc.getDisplay()->printLose();
            return 0;

        } else if (gc.getStatus() == "restart") {
            continue;

        } else if (gc.getStatus() == "die") {
            gc.getDisplay()->printLose();
            
        } else if (gc.getStatus() == "win") {
            gc.getDisplay()->printWin();
        }

        char c;
        while(1) {
            cout << "'r' to play again 'q' for quit" << endl;
            cin >> c;
            if (c == 'r' || c == 'q') {
                break;
            }
        }

        if (c == 'r') {
            continue;
        } else if (c == 'q') {
            return 0;
        }
        
    }
}
