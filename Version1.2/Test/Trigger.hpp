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
    bool has_command;
    int condition;
    string print;
    bool has_print;
    vector<string> action;
    bool has_action;
    int times;
    Status status;
    Owner owner;

    Trigger(xml_node<>* );
    virtual ~Trigger(){};
};

void setup1(xml_node<>* root, Status* S);
void setup2(xml_node<>* root, Owner* O);

#endif
