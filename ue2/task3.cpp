#include "../pg2.h"

int main() {
    int i, j, k, x[1000];
    for(i = 0; i < 1000; i++) {
        x[i] = i; 
    }
    
    cout << "Enter integer in 0...9999";
    cin >> k; 
    cout << "x[" << k << "] = " << x[k] << endl;
    return 0;
}
