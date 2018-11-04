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

/***********************For my triggers***************************/
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
bool ownerTrigger(Trigger * t){//3 conditions
    //check owner, go to it(inventory/room/container...)
    string owner = t -> owner.owner;
    //check has, (yes/no)
    string has = t -> owner.has;
    //check object,
    string object = t -> owner.object;
        //if owner + object == true && has == yes,
        // or owner + object == false && has == no, trigger activated
            //print and actions(plural), return true
    int i,j,k;
    if(owner == "inventory"){
        for(i = 0; i < inventory.size(); i++){
            if(inventory[i] == object){
                if(has == "yes"){
                    if(t->has_print){cout<<t->print<<endl;}
                    if(t->has_action){
                        for(k = 0; k < t->action.size();k++){
                            checkAction(t->action[k]);
                        }
                    }
                    return true;
                }else{return false;}
            }
        }
        if(i == inventory.size()){
            if(has == "no"){
                if(t->has_print){cout<<t->print<<endl;}
                if(t->has_action){
                    for(k = 0; k < t->action.size();k++){
                        checkAction(t->action[k]);
                    }
                }
                return true;
            }else{return false;}
        }
    }
    string owner_type = istypeof(owner);
    string object_type = istypeof(object);
    if(owner_type == "Room"){
        for(i = 0; i < rooms.size(); i++){
            if(rooms[i] -> name == owner){
                if(object_type == "Item"){
                    for(j = 0; j < rooms[i] -> item.size(); j++){
                        if(rooms[i]->item[j] == object){
                            if(has == "yes"){
                                if(t->has_print){cout<<t->print<<endl;}
                                if(t->has_action){
                                    for(k = 0; k < t->action.size();k++){
                                        checkAction(t->action[k]);
                                    }
                                }
                                return true;
                            }else{return false;}
                        }
                    }
                    if(j == rooms[i]->item.size()){
                        if(has == "no"){
                            if(t->has_print){cout<<t->print<<endl;}
                            if(t->has_action){
                                for(k = 0; k < t->action.size();k++){
                                    checkAction(t->action[k]);
                                }
                            }
                            return true;
                        }else{return false;}
                    }
                }
                if(object_type == "Container"){
                    for(j = 0; j < rooms[i] -> container.size(); j++){
                        if(rooms[i]->container[j]== object ){
                            if(has == "yes"){
                                if(t->has_print){cout<<t->print<<endl;}
                                if(t->has_action){
                                    for(k = 0; k < t->action.size();k++){
                                        checkAction(t->action[k]);
                                    }
                                }
                                return true;
                            }else{return false;}
                        }
                    }
                    if(j == rooms[i]->container.size()){
                        if(has == "no"){
                            if(t->has_print){cout<<t->print<<endl;}
                            if(t->has_action){
                                for(k = 0; k < t->action.size();k++){
                                    checkAction(t->action[k]);
                                }
                            }
                            return true;
                        }else{return false;}
                    }
                }
                if(object_type == "Creature"){
                    for(j = 0; j < rooms[i] -> creature.size(); j++){
                        if(rooms[i]->creature[j]== object){
                            if(has == "yes"){
                                if(t->has_print){cout<<t->print<<endl;}
                                if(t->has_action){
                                    for(k = 0; k < t->action.size();k++){
                                        checkAction(t->action[k]);
                                    }
                                }
                                return true;
                            }else{return false;}
                        }
                    }
                    if(j == rooms[i]->creature.size()){
                        if(has == "no"){
                            if(t->has_print){cout<<t->print<<endl;}
                            if(t->has_action){
                                for(k = 0; k < t->action.size();k++){
                                    checkAction(t->action[k]);
                                }
                            }
                            return true;
                        }else{return false;}
                    }
                }
            }
        }
    }
    if(owner_type == "Container"){
        for(i = 0; i < containers.size(); i++){
            if(containers[i]->name == owner){
                //Object can only be item
                for(j = 0; j < containers[i] -> item.size(); j++){
                    if(containers[i]->item[j]== object){
                        if(has == "yes"){
                            if(t->has_print){cout<<t->print<<endl;}
                            if(t->has_action){
                                for(k = 0; k < t->action.size();k++){
                                    checkAction(t->action[k]);
                                }
                            }
                            return true;
                        }else{return false;}
                    }
                }
                if(j == containers[i]->item.size()){
                    if(has == "no"){
                        if(t->has_print){cout<<t->print<<endl;}
                        if(t->has_action){
                            for(k = 0; k < t->action.size();k++){
                                checkAction(t->action[k]);
                            }
                        }
                        return true;
                    }else{return false;}
                }
            }
        }
    }
    return false;
}
bool statusTrigger(Trigger * t){//2 conditions
    //check object
    string object = t -> status.object;
    //check object's status
    string status = t -> status.status;
        //if it matches the status
        //print and actions(plural), return true
    int i,j;
    string object_type = istypeof(object);
    if(object_type == "Room"){
        for(i = 0; i < rooms.size(); i++){
            if(rooms[i] -> name == object){
                if(rooms[i] -> status == status){
                    if(t->has_print){cout<<t->print<<endl;}
                    if(t->has_action){
                        for(j = 0; j < t->action.size();j++){
                            checkAction(t->action[j]);
                        }
                    }
                    return true;
                }
            }
        }
    }
    if(object_type == "Item"){
        for(i = 0; i < items.size(); i++){
            if(items[i] -> name == object){
                if(items[i] -> status == status){
                    if(t->has_print){cout<<t->print<<endl;}
                    if(t->has_action){
                        for(j = 0; j < t->action.size();j++){
                            checkAction(t->action[j]);
                        }
                    }
                    return true;
                }
            }
        }
    }
    if(object_type == "Container"){
        for(i = 0; i < containers.size(); i++){
            if(containers[i] -> name == object){
                if(containers[i] -> status == status){
                    if(t->has_print){cout<<t->print<<endl;}
                    if(t->has_action){
                        for(j = 0; j < t->action.size();j++){
                            checkAction(t->action[j]);
                        }
                    }
                    return true;
                }
            }
        }
    }
    if(object_type == "Creature"){
        for(i = 0; i < creatures.size(); i++){
            if(creatures[i] -> name == object){
                if(creatures[i] -> status == status){
                    if(t->has_print){cout<<t->print<<endl;}
                    if(t->has_action){
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
    //check all triggers and pick the triggers with no command
    //if it is permanent, continue, no worry
    //else if it is single, check if it has not been executed before
    //if it is 3-cond, go to ownerTrigger()
    //else if it is 2-cond, go to statusTrigger()
    int i,j,k;
    bool rresult = false;
    bool iresult = false;
    bool cresult = false;
    bool crresult = false;
    Trigger *t;
    //current room trigger
    if(current -> trigger.size() != 0){ //has triggers~
        for(j = 0; j < current->trigger.size(); j++){
            t = current->trigger[j];
            if(!t->has_command){
                if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                    if(t->condition == 3){rresult = ownerTrigger(t);}
                    else if(t->condition == 2){rresult = statusTrigger(t);}
                    if(rresult == true){t->times++;}
                }
            }
        }
    }
    //current room's item trigger
    for(i = 0; i < current -> item.size(); i++){
        string target = current -> item[i];
        for(j = 0; j < items.size(); j++){
            if(items[j] -> name == target){
                for(k = 0; k < items[j] -> trigger.size(); k++){
                    t = items[j] -> trigger[k];
                    if(!t->has_command){
                        if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                            if(t->condition == 3){iresult = ownerTrigger(t);}
                            else if(t->condition == 2){iresult = statusTrigger(t);}
                            if(iresult == true){t->times++;}
                        }
                    }
                }
            }
        }
    }
    //current room's container trigger
    for(i = 0; i < current -> container.size(); i++){
        string target = current -> container[i];
        for(j = 0; j < containers.size(); j++){
            if(containers[j] -> name == target){
                for(k = 0; k < containers[j] -> trigger.size(); k++){
                    t = containers[j] -> trigger[k];
                    if(!t->has_command){
                        if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                            if(t->condition == 3){cresult = ownerTrigger(t);}
                            else if(t->condition == 2){cresult = statusTrigger(t);}
                            if(cresult == true){t->times++;}
                        }
                    }
                }
            }
        }
    }
    //current room's creature trigger
    for(i = 0; i < current -> creature.size(); i++){
        string target = current -> creature[i];
        for(j = 0; j < creatures.size(); j++){
            if(creatures[j] -> name == target){
                for(k = 0; k < creatures[j] -> trigger.size(); k++){
                    t = creatures[j] -> trigger[k];
                    if(!t->has_command){
                        if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                            if(t->condition == 3){crresult = ownerTrigger(t);}
                            else if(t->condition == 2){crresult = statusTrigger(t);}
                            if(crresult == true){t->times++;}
                        }
                    }
                }
            }
        }
    }
    return (rresult||iresult||cresult||crresult);
}
bool checkTrigger_withcommand(string input){
    //truncate input
    //check all triggers and pick the triggers with command
    //if it is permanent, continue, no worry
    //else if it is single, check if it has been executed before
    //if it is 3-cond, go to ownerTrigger()
    //else if it is 2-cond, go to statusTrigger()
    int i,j,k;
    bool rresult = false;
    bool iresult = false;
    bool cresult = false;
    bool crresult = false;
    Trigger *t;
    //current room trigger
    if(current -> trigger.size() != 0){ //has triggers~
        for(j = 0; j < current->trigger.size(); j++){
            t = current->trigger[j];
            if(t -> has_command && input == t -> command){
                if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                    if(t->condition == 3){rresult = ownerTrigger(t);}
                    else if(t->condition == 2){rresult = statusTrigger(t);}
                    if(rresult == true){t->times++;}
                }
            }
        }
    }
    //inventory's item trigger
    for(i = 0; i < inventory.size(); i++){
        string target = inventory[i];
        for(j = 0; j < items.size(); j++){
            if(items[j] -> name == target){
                for(k = 0; k < items[j] -> trigger.size(); k++){
                    t = items[j] -> trigger[k];
                    if(t -> has_command && input == t -> command){
                        if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                            if(t->condition == 3){iresult = ownerTrigger(t);}
                            else if(t->condition == 2){iresult = statusTrigger(t);}
                            if(iresult == true){t->times++;}
                        }
                    }
                }
            }
        }
    }
    //current room's container trigger
    for(i = 0; i < current -> container.size(); i++){
        string target = current -> container[i];
        for(j = 0; j < containers.size(); j++){
            if(containers[j] -> name == target){
                for(k = 0; k < containers[j] -> trigger.size(); k++){
                    t = containers[j] -> trigger[k];
                    if(t -> has_command && input == t -> command){
                        if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                            if(t->condition == 3){cresult = ownerTrigger(t);}
                            else if(t->condition == 2){cresult = statusTrigger(t);}
                            if(cresult == true){t->times++;}
                        }
                    }
                }
            }
        }
    }
    //current room's creature trigger
    for(i = 0; i < current -> creature.size(); i++){
        string target = current -> creature[i];
        for(j = 0; j < creatures.size(); j++){
            if(creatures[j] -> name == target){
                for(k = 0; k < creatures[j] -> trigger.size(); k++){
                    t = creatures[j] -> trigger[k];
                    if(t -> has_command && input == t -> command){
                        if(t->type == "permanent" || (t->type == "single" && t->times == 0)){
                            if(t->condition == 3){crresult = ownerTrigger(t);}
                            else if(t->condition == 2){crresult = statusTrigger(t);}
                            if(crresult == true){t->times++;}
                        }
                    }
                }
            }
        }
    }
    return (rresult||iresult||cresult||crresult);
}
#endif
