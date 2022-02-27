#include "scanner.h"

#include <string.h>

// Initialize the Scanner
void scanner_init(Scanner *scanner, const char *source)
{
    scanner->source = source;
    scanner->start  = source;
    scanner->end    = source;
    
    scanner->line   = 1;
    scanner->column = 1;
}

// Advance the Scanner
static char advance(Scanner *scanner)
{
    ++scanner->column;
    ++scanner->end;

    return scanner->end[-1];
}

// Skip whitespace
static void skip_whitespace(Scanner *scanner)
{
    for (;;)
    {
        switch (*scanner->end)
        {
            case ' ' :
            case '\r':
            case '\t':
            {
                advance(scanner);
                break;
            }

            case '\n':
            {
                advance(scanner);

                scanner->line   += 1;
                scanner->column  = 1;
                break;
            }

            case '/':
            {
                if (scanner->end[1] == '/')
                {
                    while ((*scanner->end != '\n') && (*scanner->end != '\0'))
                        advance(scanner);
                }
                else
                    return;

                break;
            }

            default:
                return;
        }
    }
}

// Make token
static uint make_token(Scanner *scanner, uint kind)
{
    scanner->current = (Token)
    {
        .kind   = kind,
        .start  = scanner->start,
        .length = (int)(scanner->end - scanner->start),
        .line   = scanner->line,
        .column = scanner->column,
    };

    return kind;
}

// Make error token
static uint make_error_token(Scanner *scanner, const char *message)
{
    scanner->current = (Token)
    {
        .kind   = token_error,
        .start  = message,
        .length = (strlen(message) - 1),
        .line   = scanner->line,
        .column = scanner->column,
    };

    return token_error;
}

// Scan token
uint scan(Scanner *scanner)
{
    skip_whitespace(scanner);

    scanner->start    = scanner->end;
    scanner->previous = scanner->current;

    if (*scanner->end == '\0')
        return make_token(scanner, token_end);

    char character = advance(scanner);

    switch (character)
    {
        default:
            return make_error_token(scanner, "Unexpected character.");
    }
}