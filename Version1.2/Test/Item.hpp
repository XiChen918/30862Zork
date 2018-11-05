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
private:
	void setupItem(xml_node<>* node){
        turnonAble = false;
		for(xml_node<>* child = node -> first_node(); child; child = child -> next_sibling()){
			if(string(child->name()) == "name"){
				name = child -> value();
			}
			if(string(child->name()) == "status"){
				status = child -> value();
			}
			if(string(child->name()) == "description"){
				description = child -> value();
			}
			if(string(child->name()) == "writing"){
				writing = child -> value();
			}
            if(string(child->name()) == "turnon"){
                turnonAble = true;
                string printmsg, actionmsg;
                for(xml_node<>* kid2 = child -> first_node();
                    kid2; kid2 = kid2 -> next_sibling()){
                    if(string(kid2->name()) == "print"){
                        printmsg = kid2 -> value();
                    }
                    if(string(kid2->name()) == "action"){
                        actionmsg = kid2->value();
                    }
                }
                turnon.print = printmsg;
                turnon.action = actionmsg;
            }
            if(string(child->name()) == "trigger"){
                Trigger * t = new Trigger(child);
                trigger.push_back(t);
            }
		}
	}
protected:
};

#endif
