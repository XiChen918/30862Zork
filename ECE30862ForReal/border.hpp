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

class border{
public:
    string direction;
    string name;

    border();
    virtual ~border(){};
};
#endif //INC_30862ZORK_MASTER_BORDER_H
