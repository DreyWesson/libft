#include "../inc/Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer   const &cpy) {
    *this = cpy;
}

Serializer::~Serializer() {}

Serializer  &Serializer::operator=(Serializer   const &src)
{
    (void)src;   
    return (*this);
}

uintptr_t   Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}