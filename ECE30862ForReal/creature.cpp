//
// Created by Owner on 11/3/2018.
//
#include <iostream>
#include "creature.hpp"
#include "Attack.hpp"
#include "trigger.hpp"

using namespace std;

Creature::Creature(xml_node<> *root) {
    string x,y,z;
    int i = 0;
    xml_node<> * branch = root -> first_node();

    while(branch != NULL){
        x = branch -> name();
        y = branch -> value();

        if(x == "name") this -> name = y;
        else if(x == "status") this -> status = y;
        else if(x == "description") this -> description = y;
        else if(x == "vulnerability") vulnerability.push_back(y);
        else if(x == "attack") this -> attack  = new Attack(branch);
        else if(x == "trigger"){
            Trigger* t = new Trigger(branch);
            trigger.push_back(t);
        }

        branch = branch -> next_sibling();
    }
}