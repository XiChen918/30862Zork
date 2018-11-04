//
// Created by Owner on 11/3/2018.
//

#include <vector>
#include <string>
#include "rapidxml.hpp"
#include "Container.hpp"
#include "Item.hpp"
#include "creature.hpp"
#include "trigger.hpp"
#include "border.hpp"

#ifndef INC_30862ZORK_MASTER_ROOM_H
#define INC_30862ZORK_MASTER_ROOM_H

using namespace rapidxml;
using namespace std;

class Room{
public:
    string name;
    string status;
    string type;
    string description;
    vector<Border*> border;
    vector<string> Container;
    vector<string> Item;
    vector<string> Creature;
    vector<Trigger*> trigger;

    Room(xml_node<>* root);
    virtual ~Room(){};
};

#endif //INC_30862ZORK_MASTER_ROOM_H
