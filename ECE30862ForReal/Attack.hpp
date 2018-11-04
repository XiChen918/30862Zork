#pragma once
#include <vector>
#include <map>
#include "Condition.hpp"
#include "rapidxml.hpp"
#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<list>

#include "Trigger.hpp"
#include "Attack.hpp"
using namespace std;
using namespace rapidxml;

typedef struct attackcondition {
	string object;
	string status;
}Condition;

class Attack {
public:
	Condition condition;
	string print;
	vector<string> action;

	bool has_condition;
	bool has_print;
	bool has_action;

	Attack(xml_node<>* node) {
		setupAttack(node);
	}
	virtual ~Attack() {};
};
