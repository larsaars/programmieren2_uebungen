#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::cout, std::endl, std::string;

class Fur {
    int len{};
    string color;

  public:
    Fur(const Fur &fur) = default;
    Fur() = default;

    void grow(int time);
    void print();
};
