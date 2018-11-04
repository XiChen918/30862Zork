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
    int i = (current -> border).size();
    int ind = 0;
    for(;ind < i; ind++){
        if(current -> border[ind] -> direction == input){
            string newroom = current -> border[ind] -> name;
            int j = rooms.size();
            for(int ind2 = 0; ind2 < j; ind2++){
                if(rooms[ind2] -> name == newroom){
                    current = rooms[ind2];
                }
            }
            break;
        }
    }
    if(ind == i){
        cout << "You can't go that way" << endl;
    }else{
        cout << current -> description << endl;
    }
}
//When reach the exit
void exit(){
    if(current -> type == "exit"){
        GameOver();
        return;
    }
    cout << "There is no exit in this room" << endl;
}

#endif /* ChangeRoom_hpp */
