#include <iostream>
#include <string>

using namespace std;

struct string_s {
    const char *s;

    string_s(const char *s) : s(s) {}
};

struct A  {
    string s;
    A(const string &s) : s(s) {}
};

int main() {
    string_s some_string_s = "bla";

    const char *c = "33";
    
    A a = (const string &) c; 


    return 0;
}
