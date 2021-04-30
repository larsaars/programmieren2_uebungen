#include "sheep.h"

Sheep::Sheep(const Sheep &sheep) : age(sheep.age), name(sheep.name) {
    *fur = *sheep.fur;
    flock = sheep.flock;
}

void Sheep::ageSheep(int time) {
    age += time;

    if(!fur)
        fur = new Fur;
    
    fur->grow(time); // (*fur).grow(time);
}

void Sheep::print() const {
    if(fur)
        fur->print();
    cout << "Name: " << name << endl
        << "Age: " << age << endl;
}
