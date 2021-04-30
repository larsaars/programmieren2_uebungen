#include "flock.h"

Flock::~Flock() {
    for(auto & i : flock)
        delete i;
}

void Flock::addSheep(Sheep* sheep) {
    flock.push_back(sheep);
}

void Flock::age(int time) {
    for(auto & i : flock) {
        i->ageSheep(time);
    }
}

void Flock::assignFlock() {
    for(auto & i : flock)
        i->flock = this;
}

void Flock::print() {
    for(auto & i : flock)
        i->print();
}
