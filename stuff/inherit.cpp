#include <iostream>
#include <string>

using std::cout, std::string, std::endl, std::ostream;

class person {
public:
    person() {
        
    }

    string what() const {
        return "basic person";
    }
};

class other : public person {
public:
    other() {

    }
    
    string what() const {
        return "other";
    }
};

ostream& operator<<(ostream &out, const person &p) {
    out << p.what();
    return out;
}

int main(int argc, char **args)  {
    other o;
    person p;

    cout << p << endl;
    cout << o << endl;
}

