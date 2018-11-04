//
// Created by Owner on 11/3/2018.
//

#include <vector>
#include <string>
#include "rapidxml.hpp"
#include "container.hpp"
#include "item.hpp"
#include "creature.hpp"
#include "trigger.hpp"
#include "border.hpp"

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
