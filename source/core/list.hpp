#ifndef CORE_LIST_HPP
#define CORE_LIST_HPP

#include <core/memory.hpp>

template <typename T> struct List
{
    T      *data;
    uint64  length;
    uint64  room;

    // Initialize The List
    void init(void)
    {
        length = 0;
        room   = 64;
        data   = memory_allocate<T>(room);
    }

    // Add Value To List
    void add(T value)
    {
        // Check For Room
        if ((length + 1) >= room)
        {
            room *= 2;
            data  = memory_reallocate<T>(data, room);
        }

        data[length++] = value;
    }

    // Get Value From List
    T get(uint64 index)
    {
        if (index >= length)
            index = 0;

        return data[index];
    }
};

#endif