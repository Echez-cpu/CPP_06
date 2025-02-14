#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h> // for uintptr_t

struct Data {
    std::string name;
    int age;
};

class Serializer {

private:
    Serializer();
    Serializer(const Serializer &source);
    Serializer &operator=(const Serializer& original_copy);
    ~Serializer();

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

};

#endif
