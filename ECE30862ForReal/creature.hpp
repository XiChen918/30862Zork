//
// Created by Owner on 11/3/2018.
//
#include <vector>
#include <string>
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
    vector<string> Vulnerability;
    Attack* attack;
    vector<Trigger*> trigger;

    Creature(xml_node<>* root);
    virtual ~Creature(){};

};

#endif //INC_30862ZORK_MASTER_CREATURE_H
