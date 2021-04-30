#include "flock.h"

int main(int argc, char **argv) {
    auto sheep1 = new Sheep, sheep2 = new Sheep;
    auto sheep3 = new Sheep(*sheep1, *sheep2);   

    sheep1->name = "Max";
    sheep2->name = "Mo";
    sheep3->name = "fuckfuckfuck";

    Flock flock;

    flock.addSheep(sheep1);
    flock.addSheep(sheep2);
    flock.addSheep(sheep3);

    flock.assignFlock();

    flock.print();

    return 0;
}
