//
// Created by Owner on 11/3/2018.
//

#include <vector>
#include <string>
#include "rapidxml.hpp"
#include "container.h"
#include "item.h"
#include "creature.h"
#include "trigger.h"
#include "border.h"

#ifndef INC_30862ZORK_MASTER_ROOM_H
#define INC_30862ZORK_MASTER_ROOM_H

using namespace rapidxml;
using namespace std;

class room{
public:
    string name;
    string status;
    string type;
    string description;
    vector<border*> Border;
    vector<string> Container;
    vector<string> Item;
    vector<string> Creature;
    vector<trigger*> Trigger;

    room(xml_node<>* root);
    virtual ~room(){};
};

#endif //INC_30862ZORK_MASTER_ROOM_H
