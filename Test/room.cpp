//
// Created by Owner on 11/4/2018.
//
#include <iostream>
#include "room.hpp"

using namespace std;
using namespace rapidxml;

Room::Room(xml_node<>* root){
    string x,y;
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
            /*Border *nb = new Border();
            for (xml_node<> *b = branch -> first_node(); b; b = b -> next_sibling()) {
                if (b -> name() == "direction") {
                    z = b -> value();
                    if(z == "north") z = "n";
                    if(z == "south") z = "s";
                    if(z == "east") z = "e";
                    if(z == "west") z = "w";
                }
                if (b -> name() == "name") a = b -> value();
            }
            nb -> direction = z;
            nb -> name = a;
            border.push_back(nb);*/
            Border * nb = new Border();
            string bdname, direction;
            for(xml_node<>* b = branch -> first_node();
                b; b = b -> next_sibling()){
                if(string(b->name()) == "name"){
                    bdname = b -> value();
                }
                if(string(b->name()) == "direction"){
                    direction = b->value();
                    if(direction == "north"){direction = "n";}
                    if(direction == "south"){direction = "s";}
                    if(direction == "west"){direction = "w";}
                    if(direction == "east"){direction = "e";}
                }
            }
            nb -> direction = direction;
            nb -> name = bdname;
            border.push_back(nb);
        }else if(x == "container") container.push_back(y);
        else if(x == "item") item.push_back(y);
        else if(x == "creature") creature.push_back(y);
        else if(x == "trigger"){
            Trigger* t = new Trigger(branch);
            trigger.push_back(t);
        }

        branch = branch -> next_sibling();
    }
}


