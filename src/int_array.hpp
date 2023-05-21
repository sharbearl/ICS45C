#ifndef INT_ARRAY_HPP
#define INT_ARRAY_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>

class Array {
public:
    Array() : len{0}, buf{nullptr} {}

    explicit Array(int len) : len{len}, buf{new int[len]} {}

    //implement these
    Array(const Array& other);
    Array(Array&& other) noexcept;

    friend void swap(Array& lhs, Array& rhs) noexcept {
        std::swap(lhs.len, rhs.len);
        std::swap(lhs.buf, rhs.buf);
    }

    //implement these
    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;

    //implement this
    ~Array() 
    {
        
    }

    int length() const {
        return len;
    }

    //add bound check
    int& operator[](int index) {
        return buf[index];
    }

    //add bound check
    const int& operator[](int index) const {
        return buf[index];
    }

    //implement this
    void fill(int val);

private:
    int len;
    int* buf;

    bool in_bounds(int index) const {
        return index >= 0 && index < len;
    }
};

inline std::ostream& operator<<(std::ostream& out, const Array& array) {
    std::stringstream temp;
    temp << std::setprecision(2) << std::fixed << std::right;

    for(int i = 0; i < array.length(); ++i) {
        temp << std::setw(8) << array[i];
    }

    out << temp.str();
    return out;
}

inline std::istream& operator>>(std::istream& in, Array& array) {
    for(int i = 0; i < array.length(); ++i) {
        in >> array[i];
    }
    
    return in;
}

#endif
