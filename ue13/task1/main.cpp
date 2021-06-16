#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

void ls(const fs::path &path) {
    unsigned long long k = 0;
    switch (status(path).type()) {
        case fs::file_type::not_found:
            cerr << "File not found: " << path.string() << endl;
            break;
        case fs::file_type::directory:
            cout << path.string() << ":" << endl;
            for(const auto &e : fs::recursive_directory_iterator(path)){
                if (!fs::is_directory(e))
                    k += fs::file_size(e);
                cout << "\t"<< k << " " << e.path().filename().string()<< endl;
            }


            //cout << path.string() << ":" << endl;
            /*for (const auto &e : fs::directory_iterator(path)){
                        std::uintmax_t size = fs::file_size(e.path());
                        cout << "\t" <<  size <<" "<<e.path().filename().string() << endl;
                    }*/

            break;
        default:
            cout << path.string() << endl;
    }
}

int main(int argc, char **argv) {
    if(argc == 1)  {
        ls(".");
        return 0;
    }

    for (int i = 1; i < argc; ++i){
        ls(argv[i]);
    }
    return 0;
}