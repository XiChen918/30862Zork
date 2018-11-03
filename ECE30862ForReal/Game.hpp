//
//  Game.hpp
//  ECE30862ForReal
//
//  Created by MichaelChen on 10/27/18.
//  Copyright © 2018 XiChen. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "rapidxml.hpp"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace rapidxml;
using namespace std;

class Game {

private:
    bool status;

public:
    Game(int i) : status(true) {}
    virtual ~Game() {}
    
    bool readXML(string);
    void parseXML(xml_node<> *);
    void setStatus(bool);
    bool getStatus();
    void runGame(string);
};
#endif /* Game_hpp */
