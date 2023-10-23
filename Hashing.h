#pragma once
#include <iostream>



size_t table_size = 3;



inline size_t division_hash(size_t key)
{
    return key % table_size;
}

inline size_t multiplication_hash(size_t key, double factor = 0.61803398875)
{
    return double(table_size) * (double(key) * factor - int(double(key) * factor));
}

inline size_t string_hash(const char* key)
{
    size_t key_length = strlen(key);

    size_t hash = 0;

    size_t factor = 31;

    for (size_t i = 0; i < key_length; ++i)
    {
        hash += size_t(key[i]) * size_t(pow(factor, i));
    }

    return hash % table_size;
}