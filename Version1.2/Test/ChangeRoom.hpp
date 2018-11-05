//
//  ChangeRoom.hpp
//  Zork
//
//  Created by MichaelChen on 11/4/18.
//  Copyright © 2018 XiChen. All rights reserved.
//

#ifndef ChangeRoom_hpp
#define ChangeRoom_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <list>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"
#include "Room.hpp"
#include "Container.hpp"
#include "Item.hpp"
#include "Creature.hpp"

void changeRoom(string input){
    int borderLength = (current -> border).size();
    int index = 0;
    for(;index < borderLength; index++){
        if(current -> border[index] -> direction == input){
            string newroom = current -> border[index] -> name;
            int roomLength = rooms.size();
            for(int index2 = 0; index2 < roomLength; index2++){
                if(rooms[index2] -> name == newroom){
                    current = rooms[index2];
                }
            }
            break;
        }
    }
    if(index == borderLength){
        cout << "Error: You can't go that way" << endl;
    }else{
        cout << current -> description << endl;
    }
}
//When reach the exit
void exit(){
    if(current -> type == "exit"){
        END = true;
        cout << "Game finished, You won Victory!" << endl;
        return;
    }
    cout << "Error: There is no exit in this room" << endl;
}

#endif /* ChangeRoom_hpp */
