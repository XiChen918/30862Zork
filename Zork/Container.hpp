#ifndef _CONTAINER_H
#define _CONTAINER_H

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

class Container{
public:
	string name;
    string status;
    string description;
    vector<string> item;
    vector<string> accept;
    vector<Trigger*> trigger;
    
	Container(xml_node<>* node){
		setupContainer(node);
	}
	virtual ~Container(){};

	void setupContainer(xml_node<>* node){
		xml_node<>* msg = node->first_node();
		while(msg){
			if(string(msg->name()) == "name"){
				name = msg -> value();
			}
            if(string(msg->name()) == "status"){
                status = msg -> value();
            }
            if(string(msg->name()) == "description"){
                description = msg -> value();
            }
            string buffer;
            if(string(msg->name()) == "item"){
                buffer = msg -> value();
                item.push_back(buffer);
            }
            if(string(msg->name()) == "accept"){
                buffer = msg -> value();
                accept.push_back(buffer);
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
