#include "header.hpp"
using namespace std;
using namespace rapidxml;

int main(int argc, char *argv[]){
    if(argc != 2){
        cout << "Error. Please enter: a.out filename.xml" <<endl;
        return 1;
    }
    file<> xmlFile(argv[1]);
    
    xml_document<> doc;
    doc.parse<0>(xmlFile.data());
    
    xml_node<> *node = doc.first_node();
    
    //Setup xml lists
    vector<xml_node<>*> roomLen;
    vector<xml_node<>*> containerLen;
    vector<xml_node<>*> itemLen;
    vector<xml_node<>*> creatureLen;
    
    for(xml_node<>*top = node -> first_node(); top; top = top -> next_sibling()){
      if(string(top->name()) == string("room")){
          roomLen.push_back(top);
      }
      if(string(top->name()) == string("container")){
          containerLen.push_back(top);
      }
      if(string(top->name()) == string("item")){
          itemLen.push_back(top);
      }
      if(string(top->name()) == string("creature")){
          creatureLen.push_back(top);
      }
    }
    
    Room *room;
    int length = roomLen.size();
    int index = 0;
    while(index < length){
      room = new Room(roomLen[index]);
      rooms.push_back(room);
      index++;
    }
    length = containerLen.size();
    index = 0;
    Container * container;
    while(index < length){
    	container = new Container(containerLen[index]);
    	containers.push_back(container);
    	index++;
    }
    length = itemLen.size();
    index = 0;
    Item * item;
    while(index < length){
      item = new Item(itemLen[index]);
      items.push_back(item);
      index++;
    }
    length = creatureLen.size();
    index = 0;
    Creature * creature;
    while(index < length){
      creature = new Creature(creatureLen[index]);
      creatures.push_back(creature);
      index++;
    }

    //Launch game
    string input;
    bool overridden = false;
    current = rooms[0];
    cout<< current -> description <<endl;
    while(true) {
        overridden = checkTrigger_nocommand();
        if(END) {
            break;
        }
        if(overridden) {
            continue;
        }
        getline(cin, input);
        if(string(input) == string("quit")) {
            cout<< "You quit the game" << endl;
            break;
        }
        overridden = checkTrigger_withcommand(input);
        if(END) {
            break;
        }
        if(overridden) {
            continue;
        }
        
        checkInput(input);
        if(END) {
            break;
        }
    }

    return 0;
}
