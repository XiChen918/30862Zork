//
//  Owner.hpp
//  Test
//
//  Created by MichaelChen on 11/4/18.
//  Copyright © 2018 XiChen. All rights reserved.
//

#ifndef Owner_hpp
#define Owner_hpp

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
bool ownerTrigger(Trigger * t) {
    string owner = t -> owner.owner;
    string has = t -> owner.has;
    string object = t -> owner.object;
    
    int i;
    int j;
    int k;
    
    if(owner == "inventory"){
        for(i = 0; i < inventory.size(); i++){
            if(inventory[i] == object){
                if(has == "yes"){
                    if(t->checkPrint){cout<<t->print<<endl;}
                    if(t->checkAction){
                        for(k = 0; k < t->action.size();k++){
                            checkAction(t->action[k]);
                        }
                    }
                    return true;
                }
                else {
                    return false;
                }
            }
        }
        if(i == inventory.size()){
            if(has == "no"){
                if(t->checkPrint){cout<<t->print<<endl;}
                if(t->checkAction){
                    for(k = 0; k < t->action.size();k++){
                        checkAction(t->action[k]);
                    }
                }
                return true;
            }
            else {
                return false;
            }
        }
    }
    string ownerType;
    string objectType;
    ownerType= istypeof(owner);
    objectType = istypeof(object);
    
    if(ownerType == "Room"){
        for(i = 0; i < rooms.size(); i++){
            if(rooms[i] -> name == owner){
                if(objectType == "Item"){
                    for(j = 0; j < rooms[i] -> item.size(); j++){
                        if(rooms[i]->item[j] == object){
                            if(has == "yes"){
                                if(t->checkPrint){cout<<t->print<<endl;}
                                if(t->checkAction){
                                    for(k = 0; k < t->action.size();k++){
                                        checkAction(t->action[k]);
                                    }
                                }
                                return true;
                            }
                            else {
                                return false;
                            }
                        }
                    }
                    if(j == rooms[i]->item.size()){
                        if(has == "no") {
                            if(t->checkPrint) {
                                cout<<t->print<<endl;
                            }
                            if(t->checkAction){
                                for(k = 0; k < t->action.size();k++) {
                                    checkAction(t->action[k]);
                                }
                            }
                            return true;
                        }
                        else {
                            return false;
                        }
                    }
                }
                if(objectType == "Container"){
                    for(j = 0; j < rooms[i] -> container.size(); j++){
                        if(rooms[i]->container[j]== object ){
                            if(has == "yes"){
                                if(t->checkPrint){cout<<t->print<<endl;}
                                if(t->checkAction){
                                    for(k = 0; k < t->action.size();k++){
                                        checkAction(t->action[k]);
                                    }
                                }
                                return true;
                            }
                            else {
                                return false;
                            }
                        }
                    }
                    if(j == rooms[i]->container.size()){
                        if(has == "no"){
                            if(t->checkPrint){cout<<t->print<<endl;}
                            if(t->checkAction){
                                for(k = 0; k < t->action.size();k++){
                                    checkAction(t->action[k]);
                                }
                            }
                            return true;
                        }
                        else {
                            return false;
                        }
                    }
                }
                if(objectType == "Creature"){
                    for(j = 0; j < rooms[i] -> creature.size(); j++){
                        if(rooms[i]->creature[j]== object){
                            if(has == "yes"){
                                if(t->checkPrint){cout<<t->print<<endl;}
                                if(t->checkAction){
                                    for(k = 0; k < t->action.size();k++){
                                        checkAction(t->action[k]);
                                    }
                                }
                                return true;
                            }
                            else {
                                return false;
                            }
                        }
                    }
                    if(j == rooms[i]->creature.size()){
                        if(has == "no"){
                            if(t->checkPrint){cout<<t->print<<endl;}
                            if(t->checkAction){
                                for(k = 0; k < t->action.size();k++){
                                    checkAction(t->action[k]);
                                }
                            }
                            return true;
                        }
                        else {
                            return false;
                        }
                    }
                }
            }
        }
    }
    if(ownerType == "Container"){
        for(i = 0; i < containers.size(); i++){
            if(containers[i]->name == owner){
                for(j = 0; j < containers[i] -> item.size(); j++){
                    if(containers[i]->item[j]== object){
                        if(has == "yes"){
                            if(t->checkPrint){cout<<t->print<<endl;}
                            if(t->checkAction){
                                for(k = 0; k < t->action.size();k++){
                                    checkAction(t->action[k]);
                                }
                            }
                            return true;
                        }
                        else {
                            return false;
                        }
                    }
                }
                if(j == containers[i]->item.size()){
                    if(has == "no"){
                        if(t->checkPrint){cout<<t->print<<endl;}
                        if(t->checkAction){
                            for(k = 0; k < t->action.size();k++){
                                checkAction(t->action[k]);
                            }
                        }
                        return true;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
    }
    return false;
}
#endif /* Owner_hpp */
