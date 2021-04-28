#pragma once

#include "fur.h"
#include "flock.h"

using std::vector;
using std::string;

class Flock;

class Sheep {
    int age, color;
    string name;

    Fur *fur = nullptr;
    Flock *flock = nullptr;

public:
    Sheep(const Sheep& sheep1, const Sheep& sheep2) : age(0), color(0), name("");
        
    void ageSheep(int time);
};

