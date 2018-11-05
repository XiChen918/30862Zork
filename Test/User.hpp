//
//  UserAction.hpp
//  Zork
//
//  Created by MichaelChen on 11/4/18.
//  Copyright © 2018 XiChen. All rights reserved.
//

#ifndef UserAction_hpp
#define UserAction_hpp

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
#include "ChangeRoom.hpp"
#include "ItemAction.hpp"
#include "Interaction.hpp"

using namespace std;
using namespace rapidxml;

/*************User Defined Functions - Handle inputs**************/

void showInventory(){
    int i = inventory.size();
    if(i == 0) {
        cout << "Inventory: Empty" << endl;
        return;
    }
    cout << "Inventory: ";
    int ind = 0;
    for(; ind < i - 1; ind++){
        cout << inventory[ind] << ",";
    }
    cout << inventory[ind] << endl;
}


#endif /* UserAction_hpp */
