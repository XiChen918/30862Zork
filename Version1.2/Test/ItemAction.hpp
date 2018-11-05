//
//  ItemAction.hpp
//  Zork
//
//  Created by MichaelChen on 11/4/18.
//  Copyright © 2018 XiChen. All rights reserved.
//

#ifndef ItemAction_hpp
#define ItemAction_hpp

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

void take(string input){
    int i;
    int j;
    int k;
    
    for(i = 0; i < (current -> item).size(); i++){
        if(current -> item[i] == input){
            inventory.push_back(input);
            (current -> item).erase((current -> item).begin() + i);
            cout << input << " has been added to inventory." << endl;
            return;
        }
    }
    
    for(i = 0; i < (current -> container).size(); i++){
        string container_name = current->container[i];
        for(j = 0; j < containers.size(); j++){
            if(containers[j]->name == container_name &&
               containers[j]->status == "unlocked"){
                for(k = 0; k < containers[j]->item.size();k++){
                    if(containers[j]->item[k] == input){
                        (current -> item).push_back(containers[j] -> item[k]);
                        containers[j] -> item.erase(containers[j]->item.begin()+k);
                        take(input);
                        return;
                    }
                }
            }
        }
    }
    cout << "Error: There is no such thing to take." << endl;
}

void drop(string input){
    for(int i = 0; i < inventory.size(); i++){
        if(inventory[i] == input){
            (current -> item).push_back(input);
            inventory.erase(inventory.begin() + i);
            cout << input << " has been dropped." << endl;
            return;
        }
    }
    cout << "Error: There is no such thing to drop." << endl;
}

void read(string input){
    for(int i = 0; i < inventory.size(); i++){
        if(inventory[i] == input){
            for(int j = 0; j < items.size(); j++){
                if(items[j] -> name == input){
                    if(items[j] -> writing.size() == 0){
                        cout<<"Error: There's nothing to read." << endl;
                    }else{
                        cout << items[j] -> writing << endl;
                    }
                }
            }
            return;
        }
    }
    cout << "Error: There is no such thing in your inventory to read." << endl;
}

void turnon(string input){
    for(int i = 0; i < inventory.size(); i++){
        if(inventory[i] == input){
            for(int j = 0; j < items.size(); j++){
                if(items[j] -> name == input){
                    if(items[j] -> turnonAble == false){
                        cout<<"Error: Item is not able to be turned on." << endl;
                    }else{
                        cout<<"You activate the "<< items[j]->name<<"."<<endl;
                        cout << items[j] -> turnon.print << endl;
                        //Require action
                        checkAction(items[j] -> turnon.action);
                    }
                }
            }
            return;
        }
    }
    cout << "Error: There is no such thing in your inventory to turn on." << endl;
}

void open(string input){
    int a;
    for(a = 0; a < current -> container.size(); a++){
        if(current -> container[a] == input){
            break;
        }
    }
    if(a == current -> container.size()){
        cout << "Error: There is no such thing here to open." << endl;
        return;
    }
    for(int i = 0; i < containers.size(); i++){
        if(containers[i] -> name == input){
            if(containers[i] -> status == "locked"){
                cout <<"Oops: "<<containers[i] -> name << " is locked." << endl;
                return;
            }
            if((containers[i] -> item).size() == 0){
                cout <<containers[i] -> name << " is empty." << endl;
                return;
            }
            containers[i] -> status = "unlocked";
            cout << containers[i] -> name << " contains ";
            int j;
            for(j = 0; j < (containers[i] -> item).size() - 1; j++){
                cout << containers[i] -> item[j] << ", ";
            }
            cout << containers[i] -> item[j] << endl;
            return;
        }
    }
}
#endif /* ItemAction_hpp */
