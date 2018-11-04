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

void checkInput(string input){
    if(input == "n" || input == "s" || input == "w" || input == "e"){
        changeRoom(input);
        return;
    }
    if(input == "i"){
        showInventory();
        return;
    }
    //take
    if(input == "take"){
        cout<<"What do you want to take? ";
        getline(cin, input);
        take(input);
        return;
    }
    if(input.find("take") != string::npos){
        input.erase(0,5);
        take(input);
        return;
    }
    //drop
    if(input == "drop"){
        cout<<"What do you want to drop? ";
        getline(cin, input);
        drop(input);
        return;
    }
    if(input.find("drop") != string::npos){
        input.erase(0,5);
        drop(input);
        return;
    }
    //read
    if(input == "read"){
        cout<<"What do you want to read? ";
        getline(cin, input);
        read(input);
        return;
    }
    if(input.find("read") != string::npos){
        input.erase(0,5);
        read(input);
        return;
    }
    //open
    if(input == "open"){
        cout<<"What do you want to open? ";
        getline(cin, input);
        if(input == "exit"){
            exit();
            return;
        }
        open(input);
        return;
    }
    if(input.find("open") != string::npos){
        input.erase(0,5);
        if(input == "exit"){
            exit();
            return;
        }
        open(input);
        return;
    }
    //put
    if(input == "put"){
        cout << "What do you want to put? ";
        getline(cin, input);
        string put_item = input;
        cout << "Where do you want to put in? ";
        getline(cin, input);
        string put_into = input;
        put(put_item, put_into);
        return;
    }
    if(input.find("put") != string::npos){
        input.erase(0,4);
        int space_pos = input.find(" "); //it's also size of item string
        string put_item = input.substr(0, space_pos);
        input.erase(0, space_pos + 4);
        string put_into = input;
        put(put_item, put_into);
        return;
    }
    //turn on
    if(input == "turn on"){
        cout<<"What do you want to turn on? ";
        getline(cin, input);
        turnon(input);
        return;
    }
    if(input.find("turn on") != string::npos){
        input.erase(0,8);
        turnon(input);
        return;
    }
    //attack
    if(input == "attack"){
        cout << "What do you want to attack? ";
        getline(cin, input);
        string monster = input;
        cout << "What do you want to attack with? ";
        getline(cin, input);
        string weapon = input;
        attack(monster, weapon);
        return;
    }
    if(input.find("attack") != string::npos){
        input.erase(0,7);
        int space_pos = input.find(" "); //it's also size of item string
        string monster = input.substr(0, space_pos);
        input.erase(0, space_pos + 6);
        string weapon = input;
        attack(monster, weapon);
        return;
    }
    cout << "Error" << endl;
}

#endif /* UserCommand_hpp */
