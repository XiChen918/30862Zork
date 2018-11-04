//
// Created by Owner on 11/3/2018.
//

#ifndef INC_30862ZORK_MASTER_BORDER_H
#define INC_30862ZORK_MASTER_BORDER_H

#include <string>
#include "rapidxml.hpp"

using namespace rapidxml;
using namespace std;

#ifndef BORDER_H_
#define BORDER_H_

class Border{
public:
    string direction;
    string name;

    Border();
    virtual ~Border(){};
};
#endif //INC_30862ZORK_MASTER_BORDER_H
