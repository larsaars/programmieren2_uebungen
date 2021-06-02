#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

using std::cout, std::endl, std::vector, std::string, std::cerr;

template<typename T>
void reverse(vector<T> &vector1) {
    int counter = vector1.size();
    int s = vector1.size();
    if (vector1.size() % 2 == 1)
        counter--;

    for (int i = 0; i < (counter / 2); i++) {
        T temp = vector1[i];
        vector1[i] = vector1[s - 1 - i];
        vector1[s - 1 - i] = temp;
    }
}

int vector_max(vector<int> &vector1) {
    if (vector1.size() == 0) {
        cerr << "No Element in vector!";
        return -1;
    }

    int max_int = vector1[0];
    for (int i = 1; i < vector1.size(); i++) {
        max_int = vector1[i] > max_int ? vector1[i] : max_int;
    }
    return max_int;
}

template<typename T>
T max_value(vector<T> &vector1, T (*func)(vector <T>)

) {
return
func(vector1);
}

int main() {
    vector<int> v1;
    for (int i = 1; i <= 10; i++) {
        v1.push_back(i);
    }

    reverse(v1);

    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    cout << endl << endl;

    vector<int> v2;
    for (int i = 1; i <= 9; i++) {
        v2.push_back(i);
    }

    reverse(v2);

    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
    cout << endl << endl;

    //vector<int> v3;
    cout << "Max value of int vector: " << vector_max(v2) << endl << endl;

    cout << "Max value of int vector by using a template: " << max_value(v2, vector_max) << endl;

    return 0;
}
