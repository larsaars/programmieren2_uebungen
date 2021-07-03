#include <iostream>

using namespace std;

template<typename A> struct B  {
    typedef A C;
};

template<typename D> D E() {

}

int main() {
    B<int>::C a = 5;

    int c = a + 3;

    cout << c << endl;
    return 0;
}
