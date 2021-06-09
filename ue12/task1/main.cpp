#include <iostream>

#include <iostream>
#include <vector>
#include <fstream>

using std::vector, std::string, std::ifstream, std::cerr, std::cout, std::cin, std::istream;

void readIn(vector<string> &text, istream &inputStream) {
    string line;
    while (getline(inputStream, line))
        text.push_back(line);
}

int main(int argc, char **argv) {
    vector<string> text;

    if (argc == 1)
        readIn(text, cin);
    else {
        for (int i = 1; i < argc; i++) {
            string input = argv[i];

            ifstream inputStream(input);
            if (!inputStream) cerr << "Can't open input file!";

            readIn(text, inputStream);
        }
    }

    for (auto &element : text) {
        cout << element << " ";
    }

    /* for(vector<string>::iterator i = text.begin(); i != text.end(); ++i) {
        cout << *i << " ";
    } */

    return 0;

}
