#include "templates.hpp"
#include <iostream>
#include <string>

int main(void) {
    std::cout << "--- Test with int ---" << std::endl;
    int a = 2;
    int b = 3;

    std::cout << "Original values: a = " << a << ", b = " << b << std::endl;

    ::swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;

    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::cout << "--------------------" << std::endl;

    std::cout << "--- Test with std::string ---" << std::endl;
    std::string c = "I love 42Prague.";
    std::string d = "I love 42prague";

    std::cout << "Original values: c = " << c << ", d = " << d << std::endl;

    ::swap(c, d);
    std::cout << "After swap: c = " << c << ", d = " << d << std::endl;

    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;

    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    return 0;
}
