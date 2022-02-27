#ifndef COMPILER_TOKEN_HPP
#define COMPILER_TOKEN_HPP

#include "types.hpp"

enum 
{
    token_end,
    token_error,

    token_string,
    token_number,
    token_identifier,

    token_lcurly,
    token_rcurly,

    token_define,

    token_put,
    token_puts,
    token_return,
};

struct Token
{
    const char *start;

    uint kind;
    uint length;
    uint line;
    uint column;
};

#endif