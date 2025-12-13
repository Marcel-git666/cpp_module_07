
template <typename T> Array<T>::Array(void) : data(NULL), length(0) {}

template <typename T>
Array<T>::Array(Array const &other) : length(other.length) {
    if (length == 0) {
        data = NULL;
        return;
    }
    data = new T[length];
    for (unsigned int i = 0; i < length; i++) {
        data[i] = other.data[i];
    }
}

template <typename T> Array<T> &Array<T>::operator=(Array const &other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        if (length > 0) {
            data = new T[length];
            for (unsigned int i = 0; i < length; i++) {
                data[i] = other.data[i];
            }
        } else {
            data = NULL;
        }
    }
    return *this;
}

template <typename T> Array<T>::~Array(void) { delete[] data; }

// Other methods
template <typename T> Array<T>::Array(unsigned int n) : data(NULL), length(n) {
    if (length > 0) {
        data = new T[length]();
    }
}

template <typename T> T const &Array<T>::operator[](unsigned int i) const {
    if (i >= length) {
        throw OutOfBoundsException();
    }
    return data[i];
}

template <typename T> T &Array<T>::operator[](unsigned int i) {
    if (i >= length) {
        throw OutOfBoundsException();
    }
    return data[i];
}

template <typename T> unsigned int Array<T>::size() const { return length; }

// Exceptions
template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
    return "Index is out of bounds (out of range).";
}

template <typename T>
std::ostream &operator<<(std::ostream &out, Array<T> const &a) {
    out << "[";
    for (unsigned int i = 0; i < a.size(); ++i) {
        out << a[i];
        if (i < a.size() - 1) {
            out << ", ";
        }
    }
    out << "]";
    return out;
}
