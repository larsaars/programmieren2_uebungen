// https://www.programiz.com/cpp-programming/public-protected-private-inheritance
#include <iostream>

using namespace std;

class Base {
    int pri = 2;

protected:
    int pro = 0;

public:
    int pub = 1;
};

class Sub1 : private Base {
    void a() {
        pri = 2;
        pro = 3;
        pub = 2;
    }
};

class Sub2 : protected Base {
    void a() {
        pri = 2;
        pro = 3;
        pub = 2;
    }
};

class Sub3 : public Base {
    void a() {
        pri = 2;
        pro = 3;
        pub = 2;
    }
};

class ChildOfSub3 : public Sub3 {
    void a() {
        pri = 3;
        pro = 3;
        pub = 3;
    }
};
