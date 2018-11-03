//
//  main.cpp
//  ECE30862ForReal
//
//  Created by MichaelChen on 10/27/18.
//  Copyright © 2018 XiChen. All rights reserved.
//
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include "rapidxml.hpp"
#include "Game.hpp"
#include <vector>
#include <stdio.h>
#include <iomanip>

using namespace std;
using namespace rapidxml;

int main(int argc, const char * argv[]) {
    // insert code here...
    if (argc < 2) {
        cout << "Error expected input" << endl;
        return EXIT_FAILURE;
    }
    string filename = argv[1];
    
    Game* g = new Game(1);
    g -> runGame(filename);
    
    return EXIT_SUCCESS;
    /*
    cout << filename << endl;
    
    ifstream input_file(filename, ios::in);

    if (!input_file) {
        cout << "Unable to open file" << endl;
        exit(1); // terminate with error
    }
    
    xml_document<> doc;
    xml_node<> * root;
    
    vector<char> buffer((istreambuf_iterator<char>(input_file)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);
    root = doc.first_node();
    */
    
    
    /*
    if (root_node == nullptr)
        cout << "failed" << endl;
    else
        cout << "success" << endl;
    */
    /*
    //read in XML
    xml_document<> doc;    // character type defaults to char
    xml_node<> * root;
    
    ifstream myfile("roomsample.xml");
    vector<char> buffer((istreambuf_iterator<char>(myfile)), istreambuf_iterator<char>());
    //std::string str((std::istreambuf_iterator<char>(myfile)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    //cout<<&buffer[0]<<endl;
    doc.parse<0>(&buffer[0]);
    root = doc.first_node();
    cout << &root << endl;
    //cout << "Name of my first node is: " << root->name() << "\n";

    
    //cout << "Name of my first node is: " << doc.first_node()->name() << "\n";

    //root = doc.first_node("Room");
    
    //cout << doc.first_node("Room") << endl;
     */
    /*if (root == NULL) {
        cout << "Not good"<< endl;
    }*/
    //root->first_node();
    
    //cout << root -> first_node() -> name() << endl;
    /*
    cout << "Name of my first node is: " << doc.first_node()->name() << "\n";
    xml_node<> *node = doc.first_node("foobar");
    cout << "Node foobar has value " << node->value() << "\n";
    for (xml_attribute<> *attr = node->first_attribute();
         attr; attr = attr->next_attribute())
    {
        cout << "Node foobar has attribute " << attr->name() << " ";
        cout << "with value " << attr->value() << "\n";
    }
    */
    //further
}

