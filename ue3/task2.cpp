#include "../pg2.h"
// split a string by delimiter
vector<string> split(string s, string delimiter) {
    size_t pos = 0;
    string token;
    vector<string> splits;

    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        splits.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    splits.push_back(s);

    return splits;
}

int main(int argc, char **argv) {
    // constant variables
    vector<string> args, database;

    // read arguments to a c++ string vector
    for (int i = 1; i < argc; i++) {
        args.push_back(argv[i]);
    }

    // read the database as string with each line as element of the vector
    // database
    ifstream dbis("database.txt");
    string line;
    while (getline(dbis, line)) {
        if (line.size() > 0) {
            database.push_back(line);
        }
    }
    dbis.close();

    // outstream of database
    ofstream dbos;
    dbos.open("database.txt", ios_base::app);

    if (argc == 2) {
        if (args[0] == "-h" || args[0] == "--help") {
            cout
                << "Manages a database of strings which can be linked with tags"
                << endl;
            cout << "-q tagname : query a tagname" << endl;
            cout << "-a tagname0,tagname1,...,tagnameN content : add a string "
                    "linked with given tags"
                 << endl;
        }
    } else if (argc == 3) {
        if (args[0] == "-q") {
            for (int i = 0; i < database.size(); i++) {
                // tag1,tag2,tag3 content 
                vector<string> entry = split(database[i], " ");
                vector<string> tags = split(entry[0], ",");

                string content = "";
                for(int j = 1; j < entry.size(); j++) {
                    if(j != 1)
                        content += " ";

                    content += entry[j];
                }

                for (int j = 0; j < tags.size(); j++) {
                    if (tags[j] == args[1])
                        cout << content << endl;
                }
            }
        }
    } else if(argc == 4) {
        if(args[0] == "-a") {
            string entry = args[1] + " " + args[2];
            dbos << entry << endl; 
            database.push_back(entry);
        }
    }

    dbos.close();
}

