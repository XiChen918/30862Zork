//
//  BehindScene.hpp
//  Zork
//
//  Created by MichaelChen on 11/4/18.
//  Copyright © 2018 XiChen. All rights reserved.
//

#ifndef BehindScene_hpp
#define BehindScene_hpp

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

void Add(string cond){
    string object_name;
    string location;//location can be room/container
    int position;
    position = cond.find(" to ");
    object_name = cond.substr(0, position);
    location = cond.substr(position + 4);
    int i;
    string object_type = istypeof(object_name);
    if(object_type == "Item"){
        for(i = 0; i < containers.size(); i++){
            if(containers[i]->name == location){
                containers[i]->item.push_back(object_name);
                return;
            }
        }
        
        for(i = 0; i < rooms.size(); i++){
            if(rooms[i]->name == location){
                rooms[i]->item.push_back(object_name);
                return;
            }
        }
    }
    if(object_type == "Creature"){
        for(i = 0; i < rooms.size(); i++){
            if(rooms[i]->name == location){
                rooms[i]->creature.push_back(object_name);
                return;
            }
        }
    }
    if(object_type == "Container"){
        for(i = 0; i < rooms.size(); i++){
            if(rooms[i]->name == location){
                rooms[i]->container.push_back(object_name);
                return;
            }
        }
    }
}
void Delete(string object_name){
    int i;
    int j;
    int k;
    for(i = 0; i < rooms.size(); i++){
        if(rooms[i]->name == object_name){
            for(j = 0; j < current -> border.size(); j++){
                if(current -> border[j] -> name == object_name){
                    current->border.erase(current->border.begin()+j);
                    return;
                }
            }
        }
    }
    for(i = 0; i < containers.size(); i++){
        if(containers[i]->name == object_name){
            for(j = 0; j < rooms.size(); j++){
                for(k = 0; k < rooms[j] -> container.size(); k++){
                    if(rooms[j] -> container[k] == object_name){
                        rooms[j] -> container.erase(rooms[j]->container.begin()+k);
                        return;
                    }
                }
            }
        }
    }
    for(i = 0; i < items.size(); i++){
        if(items[i]->name == object_name){
            for(j = 0; j < rooms.size(); j++){
                for(k = 0; k < rooms[j] -> item.size(); k++){
                    if(rooms[j] -> item[k] == object_name){
                        rooms[j] -> item.erase(rooms[j]->item.begin()+k);
                        return;
                    }
                }
            }
        }
    }
    for(i = 0; i < creatures.size(); i++){
        if(creatures[i]->name == object_name){
            for(j = 0; j < rooms.size(); j++){
                for(k = 0; k < rooms[j] -> creature.size(); k++){
                    if(rooms[j] -> creature[k] == object_name){
                        rooms[j] -> creature.erase(rooms[j]->creature.begin()+k);
                        return;
                    }
                }
            }
        }
    }
}
void Update(string cond){
    string object_name;
    string new_status;
    int position = cond.find(" to ");
    object_name = cond.substr(0, position);
    new_status = cond.substr(position + 4);
    int i;
    for(i = 0; i < rooms.size(); i++){
        if(rooms[i]->name == object_name){
            rooms[i]->status = new_status;
            return;
        }
    }
    for(i = 0; i < containers.size(); i++){
        if(containers[i]->name == object_name){
            containers[i]->status = new_status;
            return;
        }
    }
    for(i = 0; i < items.size(); i++) {
        if(items[i]->name == object_name){
            items[i]->status = new_status;
            return;
        }
    }
    for(i = 0; i < creatures.size(); i++){
        if(creatures[i]->name == object_name){
            creatures[i]->status = new_status;
            return;
        }
    }
}

void checkAction(string action){
    if(action.find("Add") != string::npos){
        Add(action.erase(0,4));
        return;
    }
    if(action.find("Delete") != string::npos){
        Delete(action.erase(0,7));
        return;
    }
    if(action.find("Update") != string::npos){
        Update(action.erase(0,7));
        return;
    }
    if(action == "Game Over"){
        //GameOver();
        END = true;
        cout << "Game finished, You won Victory!" << endl;
        return;
    }
    checkInput(action);
}

#endif /* BehindScene_hpp */
