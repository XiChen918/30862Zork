#ifndef _TRIGGER_H
#define _TRIGGER_H

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

typedef struct _status{
    string object;
    string status;
}Status;

typedef struct _owner{
    string object;
    string has;
    string owner;
}Owner;

class Trigger{
public:
    string type;
    string command;
    string print;
    vector<string> action;
    int condition;
    bool checkCommand;
    bool checkPrint;
    bool checkAction;
    
    Status status;
    Owner owner;
    
    int times;//for single
	Trigger(xml_node<>* node){
        setupTrigger(node);
	}
	virtual ~Trigger(){};
private:
    void setupTrigger(xml_node<>* node){
        checkCommand = false;
        checkAction = false;
        checkPrint = false;
        type = "single";
        times = 0;
        for(xml_node<>* child = node -> first_node(); child; child = child -> next_sibling()){
            if(string(child->name()) == "type"){
                type = child -> value();
            }
            if(string(child->name()) == "print"){
                checkPrint = true;
                print = child -> value();
            }
            if(string(child->name()) == "command"){
                checkCommand = true;
                command = child -> value();
            }
            if(string(child->name()) == "action"){
                checkAction = true;
                string buffer = child -> value();
                action.push_back(buffer);
            }
            if(string(child->name()) == "condition"){
                condition = condition_count(child);
                if(condition == 2){
                    setupStatus(child);
                }else if(condition == 3){
                    setupOwner(child);
                }
            }
        }
    }
    
    int condition_count(xml_node<>* node){
        int num = 0;
        for(xml_node<>* child = node -> first_node();
            child; child = child -> next_sibling()){
            num++;
        }
        return num;
    }
    void setupStatus(xml_node<>* node){
        for(xml_node<>* child = node -> first_node();
            child; child = child -> next_sibling()){
            if(string(child->name()) == "object"){
                status.object = child -> value();
            }
            if(string(child->name()) == "status"){
                status.status = child -> value();
            }
        }
    }
    void setupOwner(xml_node<>* node){
        for(xml_node<>* child = node -> first_node();
            child; child = child -> next_sibling()){
            if(string(child->name()) == "object"){
                owner.object = child -> value();
            }
            if(string(child->name()) == "has"){
                owner.has = child -> value();
            }
            if(string(child->name()) == "owner"){
                owner.owner = child -> value();
            }
        }
    }
};

#endif
