//
//  Game.cpp
//  ECE30862ForReal
//
//  Created by MichaelChen on 10/27/18.
//  Copyright © 2018 XiChen. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <istream>
#include <string>
#include <sstream>
#include "Game.hpp"
#include "rapidxml.hpp"

using namespace rapidxml;
using namespace std;


bool Game::readXML(string filename) {
    std::ifstream file(filename);
    
    if(!(file.is_open())){
        std::cout << "Cannot open file!" << std::endl;
        setStatus(false);
        return false;
    }
    //cout << "Check" << endl;
    //need check if file can be opened
    
    xml_document<> doc;
    xml_node<> * root;
    
    vector<char> buffer((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    
    doc.parse<0>(&buffer[0]);
    
    root = doc.first_node();
    //cout << "Check" << endl;

    if (root == NULL) {
        cout << "FAIL" << endl;
        setStatus(false);
    }
    else {
        parseXML(root->first_node());
    }
    //cout << "Check" << endl;
    return getStatus();
    
}

void Game::parseXML(xml_node<> * root){
    cout << "Enter" << endl;
    //identify the type of each class
    while(root != nullptr){
        if(string((root->name())) == "room") {
            cout << root->name() << endl;
        }
        else if(string((root->name())) == "item") {
            cout << "item" << endl;
        }
        else if(string((root->name())) == "container") {
            cout << "container" << endl;
        }
        else if(string((root->name())) == "creature") {
            cout << "creature" << endl;
        } else {
            cout << "Error" << endl;
        }
        root = root->next_sibling();
    }
    
}

void Game::setStatus(bool n) {
    this->status = n;
}

bool Game::getStatus() {
    return status;
}

void Game::runGame(string filename) {
    bool setup = readXML(filename);
    if(!setup) {
        return;
    }
}
