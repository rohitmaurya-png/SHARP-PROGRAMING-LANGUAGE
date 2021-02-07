//
// Created by Rohit Maurya on 11/13/2020.
//

#include "token.h"

token_id Token::getId()
{
    return id;
}

void Token::setId(token_id id)
{
    this->id = id;
}

string &Token::getValue()
{
    return tok;
}

int Token::getColumn()
{
    return col;
}

int Token::getLine()
{
    return line;
}

bool Token::isSingle()
{
    return id == SINGLE;
}

token_type Token::getType()
{
    return type;
}