#ifndef COMPILER_DIAGNOSTIC_HPP
#define COMPILER_DIAGNOSTIC_HPP

#include <compiler/token.hpp>

enum class DiagnosticKind : uint64
{
    Note,
    Warning,
    Error,
};

struct Diagnostic
{
    DiagnosticKind  kind;
    const char     *message;
    Token           token;
};

#endif