//
// Created by Owner on 11/3/2018.
//
#include <iostream>
#include "creature.hpp"
#include "attack.hpp"
#include "trigger.hpp"

using namespace std;

creature::creature(xml_node<> *root) {
    string x,y,z;
    int i = 0;
    xml_node<> * branch = root -> first_node();

    while(branch != NULL){
        x = branch -> name();
        y = branch -> value();

        if(x == "name") this -> name = y;
        else if(x == "status") this -> status = y;
        else if(x == "description") this -> description = y;
        else if(x == "vulnerability") Vulnerability.push_back(y);
        else if(x == "attack") this -> Attack  = new attack(branch);
        else if(x == "trigger"){
            trigger* t = new trigger(branch);
            Trigger.push_back(t);
        }

        branch = branch -> next_sibling();
    }
}