#ifndef _HEADER_H
#define _HEADER_H

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
#include "GlobalVar.hpp"
#include "BehindScene.hpp"
#include "User.hpp"
#include "UserCommand.hpp"
#include "Owner.hpp"

string istypeof(string o){
    int i;
    for(i = 0; i < rooms.size(); i++){
        if(rooms[i] -> name == o){
            return "Room";
        }
    }
    for(i = 0; i < items.size(); i++){
        if(items[i] -> name == o){
            return "Item";
        }
    }
    for(i = 0; i < containers.size(); i++){
        if(containers[i] -> name == o){
            return "Container";
        }
    }
    for(i = 0; i < creatures.size(); i++){
        if(creatures[i] -> name == o){
            return "Creature";
        }
    }
    return NULL;
}

bool statusTrigger(Trigger * t){
    string object = t -> status.object;
    string status = t -> status.status;
    int i,j;
    string objectType = istypeof(object);
    if(objectType == "Room"){
        for(i = 0; i < rooms.size(); i++){
            if(rooms[i] -> name == object){
                if(rooms[i] -> status == status){
                    if(t->checkPrint){cout<<t->print<<endl;}
                    if(t->checkAction){
                        for(j = 0; j < t->action.size();j++){
                            checkAction(t->action[j]);
                        }
                    }
                    return true;
                }
            }
        }
    }
    if(objectType == "Item"){
        for(i = 0; i < items.size(); i++){
            if(items[i] -> name == object){
                if(items[i] -> status == status){
                    if(t->checkPrint){cout<<t->print<<endl;}
                    if(t->checkAction){
                        for(j = 0; j < t->action.size();j++){
                            checkAction(t->action[j]);
                        }
                    }
                    return true;
                }
            }
        }
    }
    if(objectType == "Container"){
        for(i = 0; i < containers.size(); i++){
            if(containers[i] -> name == object){
                if(containers[i] -> status == status){
                    if(t->checkPrint){cout<<t->print<<endl;}
                    if(t->checkAction){
                        for(j = 0; j < t->action.size();j++){
                            checkAction(t->action[j]);
                        }
                    }
                    return true;
                }
            }
        }
    }
    if(objectType == "Creature"){
        for(i = 0; i < creatures.size(); i++){
            if(creatures[i] -> name == object){
                if(creatures[i] -> status == status){
                    if(t->checkPrint){cout<<t->print<<endl;}
                    if(t->checkAction){
                        for(j = 0; j < t->action.size();j++){
                            checkAction(t->action[j]);
                        }
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

bool checkTrigger_nocommand(){
    int i;
    int j;
    int k;
    bool result1 = false;
    bool result2 = false;
    bool result3 = false;
    bool result4 = false;
    Trigger *t;
    if(current -> trigger.size() != 0){
        for(j = 0; j < current->trigger.size(); j++){
            t = current->trigger[j];
            if(!t->checkCommand){
                if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                    if(t->condition == 3) {
                        result1 = ownerTrigger(t);
                    }
                    else if(t->condition == 2) {
                        result1 = statusTrigger(t);
                    }
                    if(result1 == true) {
                        t->times++;
                    }
                }
            }
        }
    }

    for(i = 0; i < current -> item.size(); i++){
        string target = current -> item[i];
        for(j = 0; j < items.size(); j++){
            if(items[j] -> name == target){
                for(k = 0; k < items[j] -> trigger.size(); k++){
                    t = items[j] -> trigger[k];
                    if(!t->checkCommand){
                        if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                            if(t->condition == 3) {
                                result2 = ownerTrigger(t);
                            }
                            else if(t->condition == 2) {
                                result2 = statusTrigger(t);
                            }
                            if(result2 == true) {
                                t->times++;
                            }
                        }
                    }
                }
            }
        }
    }

    for(i = 0; i < current -> container.size(); i++){
        string target = current -> container[i];
        for(j = 0; j < containers.size(); j++){
            if(containers[j] -> name == target){
                for(k = 0; k < containers[j] -> trigger.size(); k++){
                    t = containers[j] -> trigger[k];
                    if(!t->checkCommand){
                        if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                            if(t->condition == 3) {
                                result3 = ownerTrigger(t);
                            }
                            else if(t->condition == 2) {
                                result3 = statusTrigger(t);
                            }
                            if(result3 == true) {
                                t->times++;
                            }
                        }
                    }
                }
            }
        }
    }

    for(i = 0; i < current -> creature.size(); i++){
        string target = current -> creature[i];
        for(j = 0; j < creatures.size(); j++){
            if(creatures[j] -> name == target){
                for(k = 0; k < creatures[j] -> trigger.size(); k++){
                    t = creatures[j] -> trigger[k];
                    if(!t->checkCommand){
                        if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                            if(t->condition == 3){
                                result4 = ownerTrigger(t);
                            }
                            else if(t->condition == 2){
                                result4 = statusTrigger(t);
                            }
                            if(result4 == true){
                                t->times++;
                            }
                        }
                    }
                }
            }
        }
    }
    return (result1||result2||result3||result4);
}

bool checkTrigger_withcommand(string input){
    int i,j,k;
    bool result1 = false;
    bool result2 = false;
    bool result3 = false;
    bool result4 = false;
    Trigger *t;
    
    if(current -> trigger.size() != 0){
        for(j = 0; j < current->trigger.size(); j++){
            t = current->trigger[j];
            if(t -> checkCommand && input == t -> command){
                if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                    if(t->condition == 3) {
                        result1 = ownerTrigger(t);
                    }
                    else if(t->condition == 2) {
                        result1 = statusTrigger(t);
                    }
                    if(result1 == true) {
                        t->times++;
                    }
                }
            }
        }
    }
    
    for(i = 0; i < inventory.size(); i++){
        string target = inventory[i];
        for(j = 0; j < items.size(); j++){
            if(items[j] -> name == target){
                for(k = 0; k < items[j] -> trigger.size(); k++){
                    t = items[j] -> trigger[k];
                    if(t -> checkCommand && input == t -> command) {
                        if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                            if(t->condition == 3) {
                                result2 = ownerTrigger(t);
                            }
                            else if (t->condition == 2) {
                                result2 = statusTrigger(t);
                            }
                            if(result2 == true) {
                                t->times++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    for(i = 0; i < current -> container.size(); i++) {
        string target = current -> container[i];
        for(j = 0; j < containers.size(); j++) {
            if(containers[j] -> name == target) {
                for(k = 0; k < containers[j] -> trigger.size(); k++) {
                    t = containers[j] -> trigger[k];
                    if(t -> checkCommand && input == t -> command) {
                        if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                            if(t->condition == 3) {
                                result3 = ownerTrigger(t);
                            }
                            else if(t->condition == 2) {
                                result3 = statusTrigger(t);
                            }
                            if(result3 == true) {
                                t->times++;
                            }
                        }
                    }
                }
            }
        }
    }

    for(i = 0; i < current -> creature.size(); i++){
        string target = current -> creature[i];
        for(j = 0; j < creatures.size(); j++) {
            if(creatures[j] -> name == target) {
                for(k = 0; k < creatures[j] -> trigger.size(); k++) {
                    t = creatures[j] -> trigger[k];
                    if(t -> checkCommand && input == t -> command){
                        if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                            if(t->condition == 3) {
                                result4 = ownerTrigger(t);
                            }
                            else if(t->condition == 2) {
                                result4 = statusTrigger(t);
                            }
                            if(result4 == true) {
                                t->times++;
                            }
                        }
                    }
                }
            }
        }
    }
    return result1||result2||result3||result4;
}

#endif
