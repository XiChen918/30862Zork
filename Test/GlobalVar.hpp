//
//  GlobalVar.hpp
//  Zork
//
//  Created by MichaelChen on 11/4/18.
//  Copyright © 2018 XiChen. All rights reserved.
//

#ifndef GlobalVar_hpp
#define GlobalVar_hpp

#include <stdio.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<string>
#include<list>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
#include "Room.hpp"
#include "Container.hpp"
#include "Item.hpp"
#include "Creature.hpp"

using namespace std;
using namespace rapidxml;

//Global Declaration
vector<Room*> rooms;
vector<Container*> containers;
vector<Item*> items;
vector<Creature*> creatures;

vector<string> inventory;
bool END = false;
Room * current;
void checkInput(string);
string istypeof(string);

#endif /* GlobalVar_hpp */
