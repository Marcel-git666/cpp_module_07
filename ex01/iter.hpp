#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename F>
void iter(T *array_addr, unsigned int length, F func) {
    if (!array_addr)
        return;
    for (unsigned int i = 0; i < length; ++i) {
        func(array_addr[i]);
    }
}

#endif
