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
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
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
    vector<string> container;
    vector<string> item;
    vector<string> creature;
    vector<Trigger*> trigger;

    Room(xml_node<>* root);
    virtual ~Room(){};
};

#endif //INC_30862ZORK_MASTER_ROOM_H
