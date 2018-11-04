//
// Created by Owner on 11/3/2018.
//
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <list>
#include "rapidxml.hpp"
#include "trigger.hpp"
#include "Attack.hpp"

#ifndef INC_30862ZORK_MASTER_CREATURE_H
#define INC_30862ZORK_MASTER_CREATURE_H

using namespace rapidxml;
using namespace std;

class Creature{
public:
    string name;
    string status;
    string description;
    vector<string> vulnerability;
    Attack* attack;
    vector<Trigger*> trigger;

    Creature(xml_node<>* root);
    virtual ~Creature(){};

};

#endif //INC_30862ZORK_MASTER_CREATURE_H
