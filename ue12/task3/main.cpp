#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::ifstream, std::cout, std::endl, std::cerr, std::vector, std::string, std::istream, std::cin;

bool printLines(int &counter, istream &stream) {
    string line;
    while (std::getline(stream, line)) {
        cout << counter << " " << line << endl;
        counter--;

        if (counter == 0)
            return true;
    }

    return false;
}

int main(int argc, char **argv) {
    int counter = 10;

    if (argc == 1) {
        printLines(counter, cin);
        return 0;
    }

    for (int i = 0; i < argc; i++) {
        string input = argv[i];

        ifstream inputStream(input);
        if (!inputStream) {
            cerr << "cannot open file: " << input << endl;
            continue;
        }

        if (printLines(counter, inputStream))
            break;
    }

    return 0;
}
