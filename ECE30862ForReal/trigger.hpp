//
// Created by Owner on 11/4/2018.
//
#include <string>
#include <vector>
#include "rapidxml.hpp"
#include "status.hpp"
#include "owner.hpp"

#ifndef INC_30862ZORK_MASTER_TRIGGER_HPP
#define INC_30862ZORK_MASTER_TRIGGER_HPP

using namespace rapidxml;
using namespace std;

class trigger{
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
    status Status;
    owner Owner;

    trigger(xml_node<>* );
    virtual ~trigger(){};
};

typedef struct _status{
    string object;
    string status;
}status;

typedef struct _owner{
    string object;
    string has;
    string owner;
}owner;

#endif //INC_30862ZORK_MASTER_TRIGGER_HPP
