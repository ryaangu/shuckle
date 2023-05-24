#ifndef CORE_DICTIONARY_HPP
#define CORE_DICTIONARY_HPP

#include <core/memory.hpp>
#include <core/hash.hpp>
#include <core/compare.hpp>

#include <stdio.h>

template <typename T, typename U> struct Dictionary
{
    struct Entry
    {
        T    key;
        U    value;
        bool used;
    };

    Entry  *data;
    uint64  length;
    uint64  room;

    // Initialize The Dictionary
    void init(void)
    {
        length = 0;
        room   = 64;
        data   = memory_allocate<Entry>(room);

        // Clear Entries
        for (uint64 i = 0; i < room; ++i)
            data[i].used = false;
    }

    Entry *find_entry(Entry *entries, T key)
    {
        // Get Key Index
        uint64 index = (hash(key) % room);

        // Find Entry Slot
        for (;;)
        {
            Entry *entry = &entries[index];

            // Check For Entry
            if (!entry->used || compare(entry->key, key))
                return entry;

            // Not The Right Slot (Collision?)
            index = ((index + 1) % room); 
        }
    }
    
    void reallocate(void)
    {
        uint64  old_room;
        Entry  *old_entry;
        Entry  *new_entry;
        Entry  *new_data;

        // Store Old Room
        old_room  = room;
        room     *= 2;

        // Allocate New Data
        new_data = memory_allocate<Entry>(room);

        // Clear Entries
        for (uint64 i = 0; i < room; ++i)
            new_data[i].used = false;

        // Re-Allocate Old Values
        for (uint64 i = 0; i < old_room; ++i)
        {
            old_entry = &data[i];

            if (!old_entry->used)
                continue;

            new_entry        = find_entry(new_data, old_entry->key);
            new_entry->key   = old_entry->key;
            new_entry->value = old_entry->value;
            new_entry->used  = true;
        }

        // Set New Data
        memory_free(data);
        data = new_data;
    }

    // Set Value To Key
    void set(T key, U value)
    {
        // Check For Room
        if ((length + 1) >= room)
            reallocate();

        // Find Entry
        Entry *entry = find_entry(data, key);            

        // New Key?
        if (!entry->used)
        {
            entry->key   = key;
            entry->used  = true;
            length      += 1;
        }

        entry->value = value;
    }

    // Key Exists?
    bool exists(T key)
    {
        return find_entry(data, key)->used;
    }

    // Get Value From Key
    U get(T key)
    {
        return find_entry(data, key)->value;
    }
};

#endif