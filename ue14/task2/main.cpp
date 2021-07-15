#include <iostream>
#include <string>
#include <vector>

using std::cout, std::endl, std::string, std::vector, std::ostream;

class Scoop {
protected:
    string name;
    bool inCone{};

public:
    virtual string print() = 0;

    bool operator==(Scoop &other) {
        return other.name == name;
    }

    friend ostream& operator<<(ostream &out, Scoop &scoop) {
        return out << scoop.print();
    }
};

struct VanillaScoop : Scoop {
    VanillaScoop(boo) {
        this->name = "vanilla";
    }

    string print() override {
        return name;
    }
};

struct ChocolateScoop : Scoop {
    ChocolateScoop() {
        this->name = "chocolate";
    }

    string print() override {
        return name;
    }
};

struct PistachioScoop : Scoop {
    PistachioScoop() {
        this->name = "pistachio";
    }

    string print() override {
        return name;
    }
};

struct StrawberryScoop : Scoop {
    StrawberryScoop() {
        this->name = "strawberry";
    }
    string print() override {
        return name;
    }
};


class IceCreamParlour {
    bool inCone = true;

    IceCreamParlour() {}

    IceCreamParlour &inACone() {
        inCone = true;
        return *this;
    }

    IceCreamParlour &inABOwl() {
        inCone = false;
        return *this;
    }

};

int main() {
    IceCreamParlour h4;
    h4.inACone().one("strawberry").one("chocolate");
    h4.inABowl().one("vanilla").one("pistachio");
    h4.inACone().multiple("vanilla", "chocolate");
    return 0;
}
