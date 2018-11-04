#pragma once
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

typedef struct _turnon {
	string print;
	string action;
}Turnon;

class Item {
public:
	string name;
	string status;
	string description;
	string writing;
	Turnon turnon;
	bool turnonAble;
	vector<Trigger*> trigger;

	Item(xml_node<>* node) {
		setupItem(node);
	}
	virtual ~Item() {};
};

