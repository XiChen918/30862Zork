#ifndef _ITEM_H
#define _ITEM_H

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
#include "Trigger.hpp"
using namespace std;
using namespace rapidxml;

typedef struct _turnon{
    string print;
    string action;
}Turnon;

class Item{
public:
	string name;
    string status;
	string description;
	string writing;
    Turnon turnon;
    bool turnonAble;
    vector<Trigger*> trigger;
    
	Item(xml_node<>* node){
		setupItem(node);
	}
	virtual ~Item(){};

	void setupItem(xml_node<>* node){
        turnonAble = false;
		xml_node<>* msg = node->first_node();
		while(msg){
			if(string(msg->name()) == "name"){
				name = msg-> value();
			}
			if(string(msg->name()) == "status"){
				status = msg-> value();
			}
			if(string(msg->name()) == "description"){
				description = msg-> value();
			}
			if(string(msg->name()) == "writing"){
				writing = msg-> value();
			}
            if(string(msg->name()) == "turnon"){
                turnonAble = true;
                string printmsg, actionmsg;
				xml_node<>* msg2 = msg->first_node();
                while(msg2){
                    if(string(msg2->name()) == "print"){
                        printmsg = msg2 -> value();
                    }
                    if(string(msg2->name()) == "action"){
                        actionmsg = msg2->value();
                    }
					msg2 = msg2->next_sibling();
                }
                turnon.print = printmsg;
                turnon.action = actionmsg;
            }
            if(string(msg->name()) == "trigger"){
                Trigger * t = new Trigger(msg);
                trigger.push_back(t);
            }
			msg = msg->next_sibling();
		}
	}

};

#endif