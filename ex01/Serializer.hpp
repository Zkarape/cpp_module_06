#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <cstddef>
#include <iostream>

class Serializer
{
    Serializer();
    Serializer(const Serializer &cpy);
    Serializer &operator=(const Serializer &assign);
    ~Serializer();
public:
    template <typename T>
    static uintptr_t serialize(T *ptr)
    {
        return (reinterpret_cast<uintptr_t>(ptr));
    }
    template <typename T>
    static T *deserialize(uintptr_t raw)
    {
        return (reinterpret_cast<T *>(raw));
    }
};

#endif