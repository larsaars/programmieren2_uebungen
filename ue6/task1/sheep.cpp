#include "sheep.h"

void Sheep::ageSheep(int time) {
    age += time;

    if(!fur) 
        fur = new Fur;
    
    fur->grow(time); // (*fur).grow(time);
}

void Sheep::print() {
    if(fur)
        fur->print();
    cout << "Name: " << name << endl
        << "Age: " << age << endl;
}
