#pragma once

#include <vector>
#include <string>

#include "sheep.h"

using std::vector;
using std::string;

class Sheep;

class Flock {
    vector<Sheep*> flock;

public:
    ~Flock();
    
    void addSheep(Sheep* sheep);
    void age(int time);
    void print();
    void assignFlock();
};
