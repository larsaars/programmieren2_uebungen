#include <iostream>
 
using namespace std;

void foo(int (*func)(int)) {
    
    func(2);
}

int main() {
    int i = 0, j = 1;

    auto func = [](int p) -> int {
        return p * 2; 
    };

    foo(func);
}
