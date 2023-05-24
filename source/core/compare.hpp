#ifndef CORE_COMPARE_HPP
#define CORE_COMPARE_HPP

#include <core/string.hpp>

// Compare Any Values
template <typename T> static inline bool compare(T a, T b)
{
    return (a == b);
}

// Compare Strings
template <> inline bool compare(const char *a, const char *b)
{
    return string_compare(a, b);
}

#endif