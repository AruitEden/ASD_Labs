#include <iostream>




size_t division_hash(size_t key, size_t size);

size_t multiplication_hash(size_t key, size_t size, double factor = 0.61803398875);

size_t string_hash(const char* key, size_t size);



int main()
{
    
    const char* str = "f";

    std::cout << strlen(str) << '\n';

}



size_t division_hash(size_t key, size_t size)
{
    return key % size;
}

size_t multiplication_hash(size_t key, size_t size, double factor) 
{
    return double(size) * (double(key) * factor - int(double(key) * factor));
}

size_t string_hash(const char* key, size_t size)
{
    size_t key_length = strlen(key);

    size_t hash = 0;

    for (size_t i = 0, factor = 5; i < key_length; ++i, factor += 6)
    {
        hash += size_t(key[i]) * size_t(pow(factor, i));
    }

    return hash % size;
}
