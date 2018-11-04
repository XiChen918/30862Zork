//
// Created by Owner on 11/4/2018.
//
#include <string>
#include <vector>
#include "rapidxml.hpp"

#ifndef INC_30862ZORK_MASTER_TRIGGER_HPP
#define INC_30862ZORK_MASTER_TRIGGER_HPP

using namespace rapidxml;
using namespace std;

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
    bool has_command;
    int condition;
    string print;
    bool has_print;
    vector<string> Action;
    bool has_action;
    int times;
    Status status;
    Owner owner;

    Trigger(xml_node<>* );
    virtual ~Trigger(){};
};

void setup1(xml_node<>* root, Status* S);
void setup2(xml_node<>* root, Owner* O);

#endif //INC_30862ZORK_MASTER_TRIGGER_HPP
