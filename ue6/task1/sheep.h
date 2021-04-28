#pragma once

#include "flock.h"
#include "fur.h"

using std::string;
using std::vector;

class Flock;

class Sheep {
  public:
    int age;
    string name;

    Fur *fur = nullptr;

    Flock *flock = nullptr;

    Sheep() : age(0), name("") {}
    Sheep(const Sheep &sheep1, const Sheep &sheep2) : age(0), name("") {}

    ~Sheep() { delete fur; }

    void ageSheep(int time);
    void print();
};
