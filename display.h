#ifndef DISPLAY_H
#define DISPLAY_H

#include "panel.h"
#include <memory>
#include <string>
#include <iostream>
#include "floor.h"
using namespace std;

class Display {
    string action = "Welcome! ";
 public:
    Display(){}
    void printMap(Floor *floor) const;
    void printPanel(Floor *floor) const;
    void printPCInfo() const;
    void printLose() const;
    void printWin() const;
    string getAction() const;
    void setAction(string ac);
    ~Display() {}
};

#endif
