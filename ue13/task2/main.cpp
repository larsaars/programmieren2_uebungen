#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

// recursive find function
void find(const fs::path &path, int depth) {
    switch (status(path).type()) {
        case fs::file_type::not_found:
            cerr << "File not found: " << path.string() << endl;
            break;
        case fs::file_type::directory:
            // iterate through directory
            for (const auto &subFile : fs::directory_iterator(path)) {
                // inline depth x spaces
                for (int i = 0; i < depth; i++) {
                    if (i == depth - 1 && depth != 0) {
                        cout << "  |--";
                    } else {
                        cout << "  ";
                    }
                }

                // print out filename
                cout << subFile.path().filename().string() << endl;

                // call recursively if sub element is directory
                if (fs::is_directory(subFile))
                    find(subFile, depth + 1);
            }

            break;
        default:
            cout << path.string() << endl;
            break;
    }
}

int main(int argc, char **argv) {
    if (argc == 1) {
        find(".", 0);
        return 0;
    }

    for (int i = 1; i < argc; ++i) {
        find(argv[i], 0);
    }
    return 0;
}
