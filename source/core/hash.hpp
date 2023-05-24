#ifndef CORE_HASH_HPP
#define CORE_HASH_HPP

#include <core/types.hpp>

// Hash Any Value
template <typename T> static inline uint64 hash(T value)
{
    return static_cast<uint64>(value);
}

// Hash String
template <> inline uint64 hash(const char* string)
{
    uint64 hash = 5381;
    int    c;

    while ((c = *string++))
        hash = (((hash << 5) + hash) + c);

    return hash;
}

#endif