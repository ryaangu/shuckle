#ifndef CORE_MEMORY_HPP
#define CORE_MEMORY_HPP

#include <core/types.hpp>

extern void *memory_allocate(uint64 size);
extern void *memory_reallocate(void *memory, uint64 size);

// Free Memory 
extern void memory_free(void *memory);

// Allocate Memory
template <typename T> static inline T *memory_allocate(uint64 size)
{
    return reinterpret_cast<T *>(memory_allocate(size * sizeof(T)));
}

// Re-Allocate Memory
template <typename T> static inline T *memory_reallocate(void *memory, uint64 size)
{
    return reinterpret_cast<T *>(memory_reallocate(memory, size * sizeof(T)));
}

#endif