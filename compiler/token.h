#ifndef COMPILER_TOKEN_H
#define COMPILER_TOKEN_H

#include "types.h"

enum 
{
    token_end,
    token_error,

    token_number,
    token_identifier,

    token_define,

    token_put,
    token_puts,
    token_return,
};

typedef struct
{
    const char *start;

    uint kind;
    uint length;
    uint line;
    uint column;
} Token;

#endif