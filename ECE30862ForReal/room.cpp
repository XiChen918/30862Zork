//
// Created by Owner on 11/3/2018.
//

#include <iostream>
#include "room.h"
#include "border.h"
#include "container.h"
#include "item.h"
#include "creature.h"
#include "trigger.h"

using namespace std;

room::room(xml_node<>* root){
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
            border *nb = new border();
            for (xml_node<> *b = branch->first_node(); b; b = b->next_sibling()) {
                if (b->name() == "direction") nb->direction = b->value();
                else if (b->name() == "name") nb->name = b->value();
            }
            Border.push_back(nb);
        }else if(x == "container"){
            z = y;
            Container.push_back(z);
        }else if(x == "item"){
            z = y;
            Item.push_back(z);
        }else if(x == "creature"){
            z = y;
            Creature.push_back(z);
        }else if(x == "trigger"){
            trigger* t = new trigger(branch);
            Trigger.push_back(t);
        }
    }
}