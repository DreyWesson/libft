#include "./inc/Serializer.hpp"

int main()
{
    Data *data = new Data;
    data->stringValue = "Wolfsburg";
    data->intValue = 65;

    uintptr_t serialized = Serializer::serialize(data);
    Data* deserializedData = Serializer::deserialize(serialized);

    std::cout << "data: " << data << std::endl;
    std::cout << "serialized: " << deserializedData << std::endl;
    std::cout << "deserialized: " << deserializedData->intValue << " " << deserializedData->stringValue << std::endl;

    delete data;
    std::cout << std::endl;

    data = NULL;
    serialized = Serializer::serialize(data);
    deserializedData = Serializer::deserialize(serialized);
    std::cout << "data: " << data << std::endl;
    std::cout << "serialize: " << deserializedData << std::endl;
    std::cout << "deserialized: " << deserializedData << std::endl;
    return 0;
}
