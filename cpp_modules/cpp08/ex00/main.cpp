#include "./inc/easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

template <typename Container>
void testEasyFind(const char* containerName, Container& container, int elementToFind) {
    std::cout << "\n============= " << containerName << " TEST =============" << std::endl;

    // Populate container
    for (int i = 1; i <= 5; ++i)
        container.push_back(i * 10);

    try {
        typename Container::const_iterator foundIter = easyfind(container, elementToFind);
        std::cout << "Checking for Element " << elementToFind << ": " << *foundIter << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    // Test: Element not found
    try {
        int elementNotFound = 99;
        typename Container::const_iterator notFoundIter = easyfind(container, elementNotFound);
        std::cout << "Checking for Element " << elementNotFound << ": " << *notFoundIter << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Element not found: " << e.what() << '\n';
    }

    // Test: Empty container
    Container emptyContainer;
    try {
        typename Container::const_iterator emptyIter = easyfind(emptyContainer, 42);
        std::cout << "Checking for Element 42 in an empty container: " << *emptyIter << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Element not found in an empty container: " << e.what() << '\n';
    }

    container.clear();
}

int main() {
    std::vector<int> vecInt;
    testEasyFind("VECTOR", vecInt, 30);

    std::list<int> listInt;
    testEasyFind("LIST", listInt, 20);

    std::deque<int> dequeInt;
    testEasyFind("DEQUE", dequeInt, 40);
    return 0;
}
