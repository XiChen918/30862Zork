void setupItem(xml_node<>* node) {
	turnonAble = false;
	for (xml_node<>* kid = node->first_node();
		kid; kid = kid->next_sibling()) {
		if (string(kid->name()) == "name") {
			name = kid->value();
		}
		if (string(kid->name()) == "status") {
			status = kid->value();
		}
		if (string(kid->name()) == "description") {
			description = kid->value();
		}
		if (string(kid->name()) == "writing") {
			writing = kid->value();
		}
		if (string(kid->name()) == "turnon") {
			turnonAble = true;
			string printmsg, actionmsg;
			for (xml_node<>* kid2 = kid->first_node();
				kid2; kid2 = kid2->next_sibling()) {
				if (string(kid2->name()) == "print") {
					printmsg = kid2->value();
				}
				if (string(kid2->name()) == "action") {
					actionmsg = kid2->value();
				}
			}
			turnon.print = printmsg;
			turnon.action = actionmsg;
		}
		if (string(kid->name()) == "trigger") {
			Trigger * t = new Trigger(kid);
			trigger.push_back(t);
		}
	}
}