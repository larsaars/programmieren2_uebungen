//
// Created by larsl on 12.05.2021.
//

#include "calc.h"

using std::vector;

bool syntax_check(const vector<token> &tokens) {
    int size = (int) tokens.size();

    if (size == 0)
        return false;

    if (tokens[size - 1].kind != token::kind::value || tokens[0].kind != token::kind::value)
        return false;

    bool next_is_value = true;
    for (const token &t : tokens) {
        if (next_is_value && t.kind == token::kind::value) {
            next_is_value = !next_is_value;
        } else if (!next_is_value && t.kind == token::kind::op) {
            next_is_value = !next_is_value;
        } else
            return false;
    }

    return true;
}

double simple_eval_ltr(const vector<token> &tokens) {
    double res = tokens[0].value;

    bool is_op = true;
    for (int i = 1; i < tokens.size(); i++) {
        if (is_op) {
            double next_value = tokens[i + 1].value;
            char op = tokens[i].name[0];

            switch (op) {
                case '+':
                    res += next_value;
                    break;
                case '*':
                    res *= next_value;
                    break;
                case '-':
                    res -= next_value;
                    break;
                case '/':
                    res -= next_value;
                default:
                    break;
            }
        }

        is_op = !is_op;
    }

    return res;
}
