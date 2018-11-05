#ifndef _ATTACK_H
#define _ATTACK_H

#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<string>
#include<list>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

using namespace std;
using namespace rapidxml;

typedef struct _condition{
    string object;
    string status;
}Condition;

class Attack{
public:
    Condition condition;//can be no condition
    string print;//can be no print
    vector<string> action;
    
    bool has_condition;
    bool has_print;
    bool has_action;
    
	Attack(xml_node<>* node){
        setupAttack(node);
	}
	virtual ~Attack(){};

    void setupAttack(xml_node<>* node){
        has_condition = false;
        has_print = false;
        has_action = false;
        
		xml_node<>* msg = node->first_node();
        while(msg){
            if(string(msg->name()) == "condition"){
                has_condition = true;
				xml_node<>* msg2 = msg->first_node();
                while(msg2){
                    if(string(msg2->name()) == "object"){
                        condition.object = msg2->value();
                    }
                    if(string(msg2->name()) == "status"){
                        condition.status = msg2->value();
                    }
					msg2 = msg2->next_sibling();
                }
            }
            if(string(msg->name()) == "print"){
                has_print = true;
                print = msg-> value();
            }
            if(string(msg->name()) == "action"){
                has_action = true;
                string buffer = msg-> value();
                action.push_back(buffer);
            }
			msg = msg->next_sibling();
        }
    }
};

#endif
