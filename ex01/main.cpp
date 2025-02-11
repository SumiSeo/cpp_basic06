#include "Serializer.hpp"

int main()
{
    Data data = {42, "sumi"};

    uintptr_t raw = Serializer::serialize(&data);


    Data* ptr = Serializer::deserialize(raw);


    std::cout << "raw ID: " << raw << std::endl;
    std::cout << "Data ID: " << ptr->id << ", Name: " << ptr->name << "\n";


    return 0;
}