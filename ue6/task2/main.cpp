#include "flock.h"
#include "scientist.h"

void clone(Sheep *sheep, Scientist &scientist) {
    Sheep newSheep = *sheep;
    sheep->flock->addSheep(&newSheep);
}

int main(int argc, char **argv) {
    // create instance of scientist
    Scientist scientist;
    // create sheep
    auto sheep1 = new Sheep, sheep2 = new Sheep;
    auto sheep3 = new Sheep(*sheep1, *sheep2);
    // name them
    sheep1->name = "Max";
    sheep2->name = "Mo";
    sheep3->name = "fuckfuckfuck";
    // create the flock on heap
    Flock flock;
    // add all sheep
    flock.addSheep(sheep1);
    flock.addSheep(sheep2);
    flock.addSheep(sheep3);
    // assign them to their flock (assign flock pointer to each sheep)
    flock.assignFlock();
    // print out
    flock.print();

    cout << endl << endl;
    
    // test cloning sheep
    clone(sheep1, scientist);
    // print again after cloning
    flock.print();

    return 0;
}
