#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array {
  private:
    T *data;
    unsigned int length;

  public:
    // Orthodox Canonical Form
    Array(void);
    Array(Array const &other);
    Array &operator=(Array const &other);
    ~Array(void);

    // Other methods
    T const &operator[](unsigned int i) const;
    T &operator[](unsigned int i);
    Array(unsigned int n);
    unsigned int size() const;

    // Exceptions
    class OutOfBoundsException : public std::exception {
        const char *what() const throw();
    };
};

template <typename T>
std::ostream &operator<<(std::ostream &out, Array<T> const &a);

#include "Array.tpp"

#endif
