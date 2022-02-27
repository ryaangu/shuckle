#ifndef COMPILER_SCANNER_HPP
#define COMPILER_SCANNER_HPP

#include "token.hpp"

struct Scanner
{
    Token previous;
    Token current;

    const char *source;
    const char *start;
    const char *end;

    uint line;
    uint column;
};

// Initialize the Scanner
extern void scanner_init(Scanner &scanner, const char *source);

// Scan token
extern uint scan(Scanner &scanner);

#endif