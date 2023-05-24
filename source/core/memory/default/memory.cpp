#include <core/memory.hpp>

#include <stdlib.h>

void *memory_allocate(uint64 size)
{
    void *memory = malloc(size);

    // Check Memory
    if (!memory)
        exit(1);

    return memory;
}

void *memory_reallocate(void *memory, uint64 size)
{
    void *new_memory = realloc(memory, size);

    // Check New Memory
    if (!new_memory)
        exit(1);

    return new_memory;
}

void memory_free(void *memory)
{
    free(memory);
}