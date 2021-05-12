#include <iostream>
#include <iomanip>
#include "token.h"
#include "calc.h"

using namespace std;

int main() {
    vector<token> tokens = read_tokens(cin);

    if (syntax_check(tokens)) {
        /*for (int i = 0; i < tokens.size(); ++i)
            cout << setw(3) << i << ": " << tokens[i] << endl;*/
        cout << "= " << simple_eval_ltr(tokens) << endl;
    } else {
        cerr << "Invalid syntax" << endl;
        return -1;
    }

    return 0;
}
