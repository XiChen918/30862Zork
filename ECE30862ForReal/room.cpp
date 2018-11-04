//
// Created by Owner on 11/3/2018.
//

#include <iostream>
#include "room.hpp"

using namespace std;
using namespace rapidxml;

Room::Room(xml_node<>* root){
    string x,y,z;
    int i = 0;
    xml_node<> * branch = root -> first_node();

    while(branch != NULL){
        x = branch -> name();
        y = branch -> value();

        if(x == "name") this -> name = y;
        else if(x == "status") this -> status = y;
        else if(x == "type") this -> type = y;
        else if(x == "description") this -> description = y;
        else if(x == "border") {
            Border *nb = new Border();
            for (xml_node<> *b = branch->first_node(); b; b = b->next_sibling()) {
                if (b->name() == "direction") nb->direction = b->value();
                else if (b->name() == "name") nb->name = b->value();
            }
            border.push_back(nb);
        }else if(x == "container") Container.push_back(y);
        else if(x == "item") Item.push_back(y);
        else if(x == "creature") Creature.push_back(y);
        else if(x == "trigger"){
            Trigger* t = new Trigger(branch);
            trigger.push_back(t);
        }

        branch = branch -> next_sibling();
    }
}

