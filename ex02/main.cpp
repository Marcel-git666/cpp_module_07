#include "Array.hpp"
#include <iostream>

#define MAX_VAL 7
int main(int, char **) {
    std::cout << "--- 1. Constructor with MAX_VAL and size() ---" << std::endl;
    Array<int> numbers(MAX_VAL);
    std::cout << "Size of Array<int>: " << numbers.size() << std::endl;
    if (MAX_VAL < 20)
        std::cout << "Former Array (should have been 0): " << numbers
                  << std::endl;
    int *mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    if (MAX_VAL < 20)
        std::cout << "Array after random write: " << numbers << std::endl;

    std::cout << "------------------------------------------------"
              << std::endl;
    std::cout << "--- 3. Deep copy test ---" << std::endl;
    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        numbers[0] = 42;

        std::cout << "numbers[0] after change: " << numbers[0] << std::endl;
        std::cout << "tmp[0] (copy) has stayed: " << tmp[0] << std::endl;
        numbers[0] = tmp[0];
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "------------------------------------------------"
              << std::endl;

    std::cout << "--- 4. Exceptions test ---" << std::endl;
    try {
        numbers[-2] = 0;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
    delete[] mirror; //
    return 0;
}
