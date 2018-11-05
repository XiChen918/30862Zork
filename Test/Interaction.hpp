//
//  Interaction.hpp
//  Zork
//
//  Created by MichaelChen on 11/4/18.
//  Copyright © 2018 XiChen. All rights reserved.
//  Dealing with the action between two object

#ifndef Interaction_hpp
#define Interaction_hpp

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

void put(string a, string b){
    /*put a to b*/
    //check if a is in inventory
    int i;
    for(i = 0; i < inventory.size(); i++){
        if(inventory[i] == a){
            //Then I can put
            //check if the current room is b
            int j = 0;
            if(current -> name == b){
                drop(a);
                return;
            }
            //if room is not b, check if the room has container b
            for(j = 0; j < current -> container.size(); j++){
                if(current -> container[j] == b){
                    break;
                }
            }
            if(j == current -> container.size()){
                cout<<"Error: There is no such thing called "<<b<<" in this room."<<endl;
                return;
            }
            //room has container b, now access the container object
            for(j = 0; j < containers.size(); j++){
                if(containers[j] -> name == b){
                    //Check if it can accept a
                    if(containers[j]->accept.size() == 0){//not specified
                        containers[j] -> item.push_back(a);
                        inventory.erase(inventory.begin() + i);
                        cout << a << " has been put to "<<b<<endl;
                        if(containers[j]->status == ""){
                            containers[j]->status = "unlocked";
                        }
                        return;
                    }
                    for(int k = 0;k < containers[j]->accept.size();k++){
                        if(containers[j] -> accept[k] == a){
                            containers[j] -> item.push_back(a);
                            inventory.erase(inventory.begin() + i);
                            cout << a << " has been put to "<<b<<endl;
                            if(containers[j]->status == ""){
                                containers[j]->status = "unlocked";
                            }
                            return;
                        }
                    }
                    cout <<"Error " << b << " doesn't accept " << a << endl;
                    return;
                }
            }
            return;
        }
    }
    cout << "Error: There is no such thing in your inventory. "<<endl;
}




void attack(string monster, string weapon){
    //first, check if we have the monster in this room
    int i;
    int j;
    for(i = 0; i < current -> creature.size(); i++){
        if(current -> creature[i] == monster){
            break;
        }
    }
    //if yes, continue, if no, error message
    if(i == current -> creature.size()) {
        cout<<"Error: There is no such creature called "<<monster<<" here."<<endl;
        return;
    }
    //second, check if we have the weapon
    for(i = 0; i < inventory.size(); i++){
        if(inventory[i] == weapon){
            break;
        }
    }
    //if yes, continue, if no, error message
    if(i == inventory.size()) {
        cout<<"Error: There is no such thing called "<<weapon<<" in your inventory."<<endl;
        return;
    }
    cout<<"You assault the "<<monster<<" with the "<<weapon<<endl;
    //third, check if weapon matches the vulnerability
    for(i = 0; i<creatures.size(); i++) {
        if(creatures[i]->name == monster){
            break;
        }
    }
    for(j = 0; j < creatures[i]->vulnerability.size();j++) {
        if(creatures[i]->vulnerability[j] == weapon) {
            break;
        }
    }
    //if yes, continue, if no, error message
    if(j == creatures[i]->vulnerability.size()){
        cout<<"Oops: It seems "<<weapon<<" is useless to "<<monster<<endl;
        return;
    }
    //forth, check if we meet the condition
    if(creatures[i]->attack == NULL) {
        return;
    }
    if(creatures[i]->attack->has_condition){
        //-object - can be room/container/creature/item
        string object = creatures[i]->attack->condition.object;
        //-status
        string status = creatures[i]->attack->condition.status;
        bool found = false;
        bool match = false;
        for(j = 0; j < items.size(); j++){
            if(items[j]->name == object){
                found = true;
                match = items[j]->status == status;
                break;
            }
        }
        if(found == false){
            for(j = 0; j < rooms.size(); j++){
                if(rooms[j]->name == object){
                    found = true;
                    match = rooms[j]->status == status;
                    break;
                }
            }
        }
        if(found == false){
            for(j = 0; j < containers.size(); j++){
                if(containers[j]->name == object){
                    found = true;
                    match = containers[j]->status == status;
                    break;
                }
            }
        }
        if(found == false){
            for(j = 0; j < creatures.size(); j++){
                if(creatures[j]->name == object) {
                    found = true;
                    match = creatures[j]->status == status;
                    break;
                }
            }
        }
        //if yes, continue, if no, error message
        if(match == false){
            cout<<"Error: You need make sure "<<object<<" is "<<status<<endl;
            return;
        }
    }
    //finally, print and take actions(plural)
    if(creatures[i]->attack->has_print) {
        cout<<creatures[i]->attack->print<<endl;
    }
    if(creatures[i]->attack->has_action){
        for(j = 0; j<creatures[i]->attack->action.size();j++) {
            checkAction(creatures[i]->attack->action[j]);
        }
    }
}
#endif /* Interaction_hpp */
