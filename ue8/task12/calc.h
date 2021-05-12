//
// Created by larsl on 12.05.2021.
//

#ifndef TASK1_CALC_H
#define TASK1_CALC_H


#include "token.h"

bool syntax_check(const std::vector<token> &tokens);
double simple_eval_ltr(const std::vector<token> &tokens);

#endif //TASK1_CALC_H
