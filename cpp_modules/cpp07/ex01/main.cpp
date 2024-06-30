#include "iter.hpp"

int main()
{
    std::cout << "Integer Type:" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);
    iter(intArray, intArraySize, print<int>);

    std::cout << "\nDouble Type:" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArraySize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    iter(doubleArray, doubleArraySize, print<double>);

    std::cout << "\nString Type:" << std::endl;
    std::string stringArray[] = {"one", "two", "three", "four", "five"};
    size_t stringArraySize = sizeof(stringArray) / sizeof(stringArray[0]);
    iter(stringArray, stringArraySize, print<std::string>);

    return 0;
}


