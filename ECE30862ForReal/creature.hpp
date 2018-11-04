//
// Created by Owner on 11/3/2018.
//
#include <vector>
#include <string>
#include "rapidxml.hpp"
#include "trigger.hpp"
#include "attack.hpp"

#ifndef INC_30862ZORK_MASTER_CREATURE_H
#define INC_30862ZORK_MASTER_CREATURE_H

using namespace rapidxml;
using namespace std;

class creature{
public:
    string name;
    string status;
    string description;
    vecter<string> Vulnerability;
    attack* Attack;
    vector<trigger*> Trigger;

    creature(xml_node<>* root);
    virtual ~creature(){};

};

#endif //INC_30862ZORK_MASTER_CREATURE_H
