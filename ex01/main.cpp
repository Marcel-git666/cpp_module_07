#include "iter.hpp"
#include <iostream>
#include <string>

// Příklad šablony funkce, kterou předáme jako 3. parametr
template <typename T> void printElement(T const &element) {
    std::cout << "[" << element << "] ";
}

// Příklad normální funkce (pro int)
void incrementInt(int &n) { n++; }

int main() {
    // --- TEST 1: Pole int ---
    int intArr[] = {1, 2, 3, 4, 5};
    unsigned int len = sizeof(intArr) / sizeof(intArr[0]);

    std::cout << "Original int array: ";
    ::iter(intArr, len, printElement<int>);
    std::cout << std::endl;

    ::iter(intArr, len, incrementInt);

    std::cout << "Incremented array: ";
    ::iter(intArr, len, printElement<int>);
    std::cout << std::endl;
    // Očekávaný výstup: [2] [3] [4] [5] [6]

    std::cout << "---------------------------------" << std::endl;

    // --- TEST 2: Pole string ---
    std::string strArr[] = {"Hello", "World", "Templates"};
    unsigned int strLen = 3;

    std::cout << "String array: ";
    ::iter(strArr, strLen, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
