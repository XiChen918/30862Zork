//
// Created by Owner on 11/4/2018.
//

#include <iostream>
#include "trigger.hpp"

using namespace std;
using namespace rapidxml;

Trigger::Trigger(xml_node<> * root) {
    string x,y;
    this -> type = "single";
    this -> has_action = false;
    this -> has_command = false;
    this -> has_print =false;
    this -> times = 0;
    xml_node<>* branch = root -> first_node();
    xml_node<>* b;
    int i = 0;

    while(branch != NULL){
        x = branch -> name();
        y = branch -> value();

        if(x == "type") this -> type = y;
        else if(x == "command"){
            this -> command =y;
            this -> has_command = true;
        }else if(x == "condition"){
            b = branch -> first_node();
            while(b != NULL){
                i++;
                b = b-> next_sibling();
            }
            this -> condition = i;
            if(this -> condition == 2) setup1(branch, &this -> status);
            else if(this -> condition == 3) setup2(branch, &this -> owner);
        }else if(x == "print") {
            this -> print = y;
            this -> has_print = true;
        }else if(x == "action"){
            Action.push_back(y);
            this -> has_action = true;
        }

        branch = branch -> next_sibling();
    }
}
void setup1(xml_node<>* root, Status* S){
    xml_node<>* branch = root -> first_node();
    string x,y;

    while(branch != NULL){
        x = branch -> name();
        y = branch -> value();

        if(x == "object") S.object = y;
        else if(x == "status") S.status =y;

        branch = branch -> next_sibling();
    }
}

void setup2(xml_node<>* root, Owner* O) {
    xml_node<> *branch = root->first_node();
    string x, y;

    while (branch != NULL) {
        x = branch->name();
        y = branch->value();

        if(x == "object") O.object = y;
        else if(x == "has") O.has = y;
        else if(x == "owner") O.owner = y;

        branch = branch -> next_sibling();
    }
}