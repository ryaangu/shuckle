#include <core/string.hpp>

uint64 string_length(const char *string)
{
    const char *base = string;

    while (*string++);

    return (static_cast<uint64>(string - base) - 1);
}

bool string_compare(const char *a, const char *b)
{
    uint64 a_length = string_length(a);
    uint64 b_length = string_length(b);

    // Compare Lengths 
    if (a_length != b_length)
        return false;

    // Compare Characters
    for (uint64 i = 0; i < a_length; ++i)
        if (a[i] != b[i])
            return false;

    return true;
}