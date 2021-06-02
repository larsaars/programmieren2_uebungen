#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

using std::cout, std::endl, std::vector, std::string, std::cerr;

// (A)
template<typename T>
void reverse(vector<T> &v) {
    int counter = v.size(), size = counter;

    if (size % 2 == 1)
        counter--;

    for (int i = 0; i < (counter / 2); i++) {
        T temp = v[i];
        v[i] = v[size - 1 - i];
        v[size - 1 - i] = temp;
    }
}

// (B)
int vector_max(const vector<int> &v) {
    if (v.empty()) {
        cerr << "No Element in vector!";
        return -1;
    }

    int max_int = v[0];
    for (int i = 1; i < v.size(); i++)
        if (v[i] > max_int)
            max_int = v[i];

    // max_int = v[i] > max_int ? v[i] : max_int;

    return max_int;
}


// (C)
template<typename T>
int largest(const vector<T> &v, int (*sizeFunc)(const T &)) {
    if (v.empty()) {
        cerr << "No Element in vector!";
        return -1;
    }

    int maxValue = sizeFunc(v[0]), maxIndex = 0;
    for (int i = 1; i < v.size(); i++) {
        int sizeI = sizeFunc(v[i]);

        if (sizeI > maxValue) {
            maxValue = sizeI;
            maxIndex = i;
        }
    }

    return maxIndex;
}

int stringlength(const string &s) { return s.length(); }


int main() {
    // (A)
    vector<int> v1;
    for (int i = 1; i <= 10; i++)
        v1.push_back(i);

    reverse(v1);

    for (int i : v1)
        cout << i << " ";
    cout << endl << endl;

    vector<int> v2;
    for (int i = 1; i <= 9; i++)
        v2.push_back(i);

    reverse(v2);

    for (int i : v2)
        cout << i << " ";
    cout << endl << endl;

    // (B)
    cout << "Max value of int vector: " << vector_max(v2) << endl << endl;


    // (C)
    vector<string> strings = { "Schreiben", "Sie", "eine", "Template -Funktion", "die" };
    int index = largest(strings, stringlength); // == 3 ?
    cout << index << endl;

    return 0;
}
