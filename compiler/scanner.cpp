#include "scanner.hpp"

#include <string.h>

// Initialize the Scanner
void scanner_init(Scanner &scanner, const char *source)
{
    scanner.source = source;
    scanner.start  = source;
    scanner.end    = source;
    
    scanner.line   = 1;
    scanner.column = 1;
}

// Advance the Scanner
static char advance(Scanner &scanner)
{
    ++scanner.column;
    ++scanner.end;

    return scanner.end[-1];
}

// Skip whitespace
static void skip_whitespace(Scanner &scanner)
{
    for (;;)
    {
        switch (*scanner.end)
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

                scanner.line   += 1;
                scanner.column  = 1;
                break;
            }

            case '/':
            {
                if (scanner.end[1] == '/')
                {
                    while ((*scanner.end != '\n') && (*scanner.end != '\0'))
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
static uint make_token(Scanner &scanner, uint kind)
{
    scanner.current.kind   = kind;
    scanner.current.start  = scanner.start;
    scanner.current.length = static_cast<int>(scanner.end - scanner.start);
    scanner.current.line   = scanner.line;
    scanner.current.column = scanner.column;

    return kind;
}

// Make error token
static uint make_error_token(Scanner &scanner, const char *message)
{
    scanner.current.kind   = token_error;
    scanner.current.start  = message;
    scanner.current.length = (strlen(message) - 1);
    scanner.current.line   = scanner.line;
    scanner.current.column = scanner.column;

    return token_error;
}

// Make string token
static uint make_string_token(Scanner &scanner)
{
    while ((*scanner.end != '"') && (*scanner.end != '\0'))
        advance(scanner);

    if (*scanner.end == '\0')
        return make_error_token(scanner, "Unterminated string.");

    advance(scanner);
    return make_token(scanner, token_string);
}

// Is character a digit?
static bool is_digit(char character)
{
    return (character >= '0' && character <= '9');
}

// Is character an identifier character?
static bool is_identifier(char character)
{
    return (character >= 'A' && character <= 'Z') ||
           (character >= 'a' && character <= 'z') ||
           (character == '_');
}

// Make number token
static uint make_number_token(Scanner &scanner)
{
    while (is_digit(*scanner.end))
        advance(scanner);

    if (*scanner.end == '.')
    {
        advance(scanner);

        while (is_digit(*scanner.end))
            advance(scanner);
    }

    return make_token(scanner, token_number);
}

// Make identifier token
static uint make_identifier_token(Scanner &scanner)
{
    while (is_identifier(*scanner.end) || is_digit(*scanner.end))
        advance(scanner);
    
    uint   kind   = token_identifier;
    size_t length = (size_t)(scanner.end - scanner.start);

    if (strncmp(scanner.start, "define", length) == 0)
        kind = token_define;
    else if (strncmp(scanner.start, "put", length) == 0)
        kind = token_put;
    else if (strncmp(scanner.start, "puts", length) == 0)
        kind = token_puts;
    else if (strncmp(scanner.start, "return", length) == 0)
        kind = token_return;

    return make_token(scanner, kind);
}

// Scan token
uint scan(Scanner &scanner)
{
    skip_whitespace(scanner);

    scanner.start    = scanner.end;
    scanner.previous = scanner.current;

    if (*scanner.end == '\0')
        return make_token(scanner, token_end);

    char character = advance(scanner);

    if (is_digit(character))
        return make_number_token(scanner);

    if (is_identifier(character))
        return make_identifier_token(scanner);

    switch (character)
    {
        case '{':
            return make_token(scanner, token_lcurly);
            
        case '}':
            return make_token(scanner, token_rcurly);

        case '"':
            return make_string_token(scanner);

        default:
            return make_error_token(scanner, "Unexpected character.");
    }
}