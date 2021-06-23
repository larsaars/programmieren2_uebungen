#include <iostream>
#include <string>

using std::string, std::cout, std::endl, std::cerr;

class Animal {
public:
    string name;
    int legs;

    Animal() = default;

    Animal(const string &name, int beine) : name(name), legs(beine) {}

    ~Animal() {};

    virtual void printName() {
        std::cout << "Name: " << name << std::endl;
    }

    virtual void printLegs() {
        std::cout << "Anzahl Beine: " << legs << std::endl;
    }

    friend std::ostream &operator<<(std::ostream &out, const Animal &r) {
        out << "Das Animal heißt " << r.name << " und hat " << r.legs << " Beine.";
        return out;
    }
};

class Mammal : public Animal {
public:
    explicit Mammal(const string &name) : Animal::Animal(name, 4) {}

    ~Mammal() = default;

    void printName() override {
        cout << "Name des Saeugetiers: " << name << std::endl;
    }

    void printLegs() override {
        cout << "Anzahl Beine (Saeugetier): " << legs << std::endl;
    }

};

class Insect : public Animal {
public:
    explicit Insect(const string &name) : Animal::Animal(name, 6) {}

    ~Insect() = default;

    void printName() override {
        cout << "Name des Insekts: " << name << std::endl;
    }

    void printLegs() override {
        cout << "Anzahl Beine (Insekt): " << legs << std::endl;
    }
};

class ZooAnimal : public Animal {
    virtual void feed() = 0;
};

int main() {
    Animal ferd("kleiner Onkel", 4);
    cout << ferd << endl;
    ferd.printLegs();
    ferd.printName();
    cout << endl;

    Mammal affe("Petra");
    cout << affe << endl;
    affe.printLegs();
    affe.printName();
    cout << endl;

    Insect fly("Hugo");
    cout << fly << endl;
    fly.printLegs();
    fly.printName();

    return 0;
}