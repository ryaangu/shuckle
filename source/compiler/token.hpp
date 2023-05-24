#ifndef COMPILER_TOKEN_HPP
#define COMPILER_TOKEN_HPP

#include <core/types.hpp>

enum class TokenKind : uint64
{
    End,
    Error,
};

struct Token
{
    TokenKind   kind;
    const char *start;
    const char *line_start;
    uint32      line;
    uint32      column;
};

#endif