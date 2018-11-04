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

void setupAttack(xml_node<>* node) {
	has_condition = false;
	has_print = false;
	has_action = false;

	xml_node<>* kid = node->first_node();

	while(kid) {
		if (string(kid->name()) == "condition") {
			has_condition = true;
			xml_node<>* kid2 = kid->first_node();
			while(kid2) {
				if (string(kid2->name()) == "object") {
					condition.object = kid2->value();
				}
				if (string(kid2->name()) == "status") {
					condition.status = kid2->value();
				}
				kid2 = kid2->next_sibling();
			}
		}
		if (string(kid->name()) == "print") {
			has_print = true;
			print = kid->value();
		}
		if (string(kid->name()) == "action") {
			has_action = true;
			string buffer = kid->value();
			action.push_back(buffer);
		}
		kid = kid->next_sibling();
	}
}
};
