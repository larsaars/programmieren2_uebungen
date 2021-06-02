#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::cout, std::endl, std::vector, std::string;

template<typename T> void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 0, b = 1;
    swap(a, b);

    cout << "a==" << a << " b==" << b << endl;

    std::vector<float> v1, v2;
    v1.push_back(0.0);
    v1.push_back(0.1);
    v2.push_back(1.0);
    v2.push_back(1.1);
    swap(v1, v2);

    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    cout << endl;

    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
    cout << endl << endl;

    vector<string> s1, s2;
    s1.push_back("Sting 1");
    s1.push_back("String 1.1");
    s2.push_back("String 2");
    s2.push_back("String 2.1");
    swap(s1, s2);

    for (int i = 0; i < s1.size(); i++)
        cout << s1[i] << " ";
    cout << endl;

    for (int i = 0; i < s2.size(); i++)
        cout << s2[i] << " ";
    cout << endl << endl;


    vector<string> s3;
    for (int i = 0; i < 8; i++) {
        string str = "String ";
        std::stringstream ss;
        ss << i;
        s3.push_back(str.append(ss.str()));
    }

    for (int i = 0; i < s3.size()-1; i+=2)
        swap(s3[i], s3[i+1]);

    for (int i = 0; i < s3.size(); i++)
        cout << s3[i] << " ";
    cout << endl << endl;

    return 0;
}
