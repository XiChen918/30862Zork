//
//  UserCommand.hpp
//  Zork
//
//  Created by MichaelChen on 11/4/18.
//  Copyright © 2018 XiChen. All rights reserved.
//

#ifndef UserCommand_hpp
#define UserCommand_hpp

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

void checkInput(string command){
    if(command == "n" || command == "s" || command == "w" || command == "e"){
        changeRoom(command);
        return;
    }
    if(command == "i"){
        showInventory();
        return;
    }
    //take
    if(command == "take"){
        cout<<"What do you want to take? Just enter the name of the item" << endl;
        getline(cin, command);
        take(command);
        return;
    }
    if(command.find("take") != string::npos){
        command.erase(0,5);
        take(command);
        return;
    }
    //drop
    if(command == "drop"){
        cout<<"What do you want to drop? Format: Just enter the name of the item" << endl;
        getline(cin, command);
        drop(command);
        return;
    }
    if(command.find("drop") != string::npos){
        command.erase(0,5);
        drop(command);
        return;
    }
    //read
    if(command == "read"){
        cout<<"What do you want to read? Just enter the name of the item" << endl;
        getline(cin, command);
        read(command);
        return;
    }
    if(command.find("read") != string::npos){
        command.erase(0,5);
        read(command);
        return;
    }
    //open
    if(command == "open"){
        cout<<"What do you want to open? Just enter the name of the item" << endl;
        getline(cin, command);
        if(command == "exit"){
            exit();
            return;
        }
        open(command);
        return;
    }
    if(command.find("open") != string::npos){
        command.erase(0,5);
        if(command == "exit"){
            exit();
            return;
        }
        open(command);
        return;
    }
    //put
    if(command == "put"){
        cout << "What do you want to put? Just enter the name of the item" << endl;
        getline(cin, command);
        string put_item = command;
        cout << "Where do you want to put in? Just enter the name of the item" << endl;
        getline(cin, command);
        string put_into = command;
        put(put_item, put_into);
        return;
    }
    if(command.find("put") != string::npos){
        command.erase(0,4);
        int space_pos = command.find(" "); //it's also size of item string
        string put_item = command.substr(0, space_pos);
        command.erase(0, space_pos + 4);
        string put_into = command;
        put(put_item, put_into);
        return;
    }
    //turn on
    if(command == "turn on"){
        cout<<"What do you want to turn on? Just enter the name of the item" << endl;
        getline(cin, command);
        turnon(command);
        return;
    }
    if(command.find("turn on") != string::npos){
        command.erase(0,8);
        turnon(command);
        return;
    }
    //attack
    if(command == "attack"){
        cout << "What do you want to attack? Just enter the name of the creature" << endl;
        getline(cin, command);
        string monster = command;
        cout << "What do you want to attack with? Just enter the name of the item" << endl;
        getline(cin, command);
        string weapon = command;
        attack(monster, weapon);
        return;
    }
    if(command.find("attack") != string::npos){
        command.erase(0,7);
        int space_pos = command.find(" "); //it's also size of item string
        string monster = command.substr(0, space_pos);
        command.erase(0, space_pos + 6);
        string weapon = command;
        attack(monster, weapon);
        return;
    }
    cout << "Error" << endl;
}

#endif /* UserCommand_hpp */
