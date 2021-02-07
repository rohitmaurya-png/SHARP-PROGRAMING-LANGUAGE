//
// Created by Rohit Maurya on 11/14/2020.
//

#include "Expression.h"
#include "data/Utype.h"

void Expression::init() {
    type = exp_undefined;
    utype = new Utype();
    ast = NULL;
}

void Expression::copy(Expression *expr) {
    type = expr->type;
    ast = expr->ast;
    utype->copy(expr->utype);
}
