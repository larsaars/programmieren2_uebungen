#include <string>
#include <vector>
#include <iostream>

using namespace std;

template<typename T, template<typename> class C>
T *max(C<T> &container) {
    T *max0 = &container[0];

    for (int i = 1; i < container.size(); i++) {
        if (container[i] > *max0)
            max0 = &container[i];
    }

    return max0;
}

template<typename T>
struct cont {
    vector<T> v;

    int size() {
        return v.size();
    }

    T &operator[](int index) {
        return v[index];
    }
};

int main() {
    vector<int> ints {1, 2, 3, 4};

    cont<int> ints2 {{1, 2, 4, 10}};

    cout << *max(ints2) << endl;
    
    cout << *max<int, vector>(ints) << endl;


}
