#ifndef COMPILER_SCANNER_H
#define COMPILER_SCANNER_H

#include "token.h"

typedef struct 
{
    Token previous;
    Token current;

    const char *source;
    const char *start;
    const char *end;

    uint line;
    uint column;
} Scanner;

// Initialize the Scanner
extern void scanner_init(Scanner *scanner, const char *source);

// Scan token
extern uint scan(Scanner *scanner);

#endif