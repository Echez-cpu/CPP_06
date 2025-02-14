#include "../includes/Serializer.hpp"

int main() {
    Data originalData;
    originalData.name = "Jesus is Lord";
    originalData.age = 30;

    
    uintptr_t raw = Serializer::serialize(&originalData);
    std::cout << "Serialized value: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "Deserialized Data -> Name: " << deserializedData->name << ", Age: " << deserializedData->age << std::endl;

    if (deserializedData == &originalData)
        std::cout << "Serialization and deserialization successful!" << std::endl;
    else
        std::cout << "Serialization failed!" << std::endl;

    return 0;
}
