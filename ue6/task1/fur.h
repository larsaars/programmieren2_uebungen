#pragma once

#include <vector>
#include <string>
#include <iostream>

using std::string;
using std::cout, std::endl;

class Fur {
    int len;
    string color = "";

public:
    void grow(int time);
    void print();
};


