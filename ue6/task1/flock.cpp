#include "flock.h"

Flock::~Flock() {
    for(int i = 0; i < flock.size(); i++)
        delete flock[i];
}

void Flock::addSheep(Sheep* sheep) {
    flock.push_back(sheep);
}

void Flock::age(int time) {
    for(int i = 0; i < flock.size(); i++) {
        flock[i]->ageSheep(time);
    }
}

void Flock::assignFlock() {
    for(int i = 0; i < flock.size(); i++);
        flock[i]->flock = this;
}

void Flock::print() {
    for(int i = 0; i < flock.size(); i++)
        flock[i]->print();
}
