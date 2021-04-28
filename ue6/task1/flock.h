#pragma once

#include <vector>
#include <string>

#include "sheep.h"

using std::vector;
using std::string;

class Sheep;

class Flock {
    vector<Sheep*> sheep;

public:
    Flock(const vector<Sheep*>& sheep0) : sheep(sheep0) {}

    ~Flock() {

    }

    void addSheep(const Sheep& sheep);
    void age(int time);
};
