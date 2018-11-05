#ifndef _CREATURE_H
#define _CREATURE_H

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
#include "Attack.hpp"
using namespace std;
using namespace rapidxml;

class Creature{
public:
    string name;
    string status;
    string description;
    vector<string> vulnerability;
    Attack* attack;
    vector<Trigger*> trigger;

    Creature(xml_node<>* root);
    virtual ~Creature(){};

};

#endif