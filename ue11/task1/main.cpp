#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::cout, std::endl, std::vector, std::string;

template<typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 0, b = 1;
    swap(a, b);

    cout << "a==" << a << " b==" << b << endl << endl;

    std::vector<float> v1, v2;
    v1.push_back(0.0);
    v1.push_back(0.1);
    v2.push_back(1.0);
    v2.push_back(1.1);
    swap(v1, v2);

    for (float i : v1)
        cout << i << " ";
    cout << endl;

    for (float i : v2)
        cout << i << " ";
    cout << endl << endl;

    vector<string> s1, s2;
    s1.push_back("Sting 1.0");
    s1.push_back("String 1.1");
    s2.push_back("String 2.0");
    s2.push_back("String 2.1");
    swap(s1, s2);

    for (auto & i : s1)
        cout << i << " ";
    cout << endl;

    for (auto & i : s2)
        cout << i << " ";
    cout << endl << endl;


    vector<string> s3;
    // [String 1; String 2 ...]
    for (int i = 0; i < 8; i++) {
        string str = "string ";
        std::stringstream ss;
        ss << i;
        s3.push_back(str + ss.str());
    }

    /*s3.push_back("hallo");
    s3.push_back("test");
    s3.push_back("...");
    s3.push_back("4");*/

    for (int i = 0; i < s3.size() - 1; i += 2)
        swap(s3[i], s3[i + 1]);

    for (auto & i : s3)
        cout << i << " ";
    cout << endl << endl;

    return 0;
}
