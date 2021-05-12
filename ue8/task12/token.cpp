#include "token.h"

using namespace std;

ostream &operator<<(ostream &out, const token &t) {
    out << "#tok[";
    switch (t.kind) {
        case token::kind::value:
            out << "V:" << t.value;
            break;
        case token::kind::name:
            out << "N:" << t.name;
            break;
        case token::kind::op:
            out << "O:" << t.name;
            break;
    }
    out << "]";
    return out;
}

bool isOperator(char x) {
    return x == '+' || x == '-' || x == '*' || x == '/';
}

vector<token> read_tokens(istream &in) {
    vector<token> result;
    while (true) {
        string name;
        double value;

        char c = in.get();
        if(c == '\n')
            break;

        if (isdigit(c)) {
            in.putback(c);
            in >> value;
            result.push_back(token(value));
        } else if (isalpha(c)) {
            do {
                name += c;
                in.get(c);
            } while (isalnum(c));
            in.putback(c);
            result.push_back(token(name));
        } else if (isOperator(c)) {
            name = c;
            result.push_back(token(token::kind::op, name));
        } else
            continue;
    }
    return result;
}
