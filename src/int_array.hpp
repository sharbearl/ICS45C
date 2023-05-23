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

    Array(const Array& other) : len{other.len}, buf{new int[len]}
    {    
        copy(other.buf);
    }
    
    Array(Array&& other) noexcept : len{other.len}, buf{other.buf}
    {
        other.len = 0;
        other.buf = nullptr;
    }

    friend void swap(Array& lhs, Array& rhs) noexcept {
        std::swap(lhs.len, rhs.len);
        std::swap(lhs.buf, rhs.buf);
    }

    Array& operator=(const Array& other)
    {
        if(&other != this)
        {
            delete[] buf;
            len = other.len;
            buf = new int[len];

            copy(other.buf);
        }

        return *this;
    }
    
    Array& operator=(Array&& other) noexcept
    {
        swap(*this, other);
        return *this;
    }

    ~Array() 
    {
        delete[] buf;
    }

    int length() const {
        return len;
    }

    int& operator[](int index) {
        if(!in_bounds(index))
        {
            std::ostringstream s;
            s << "Exception operator[](" << len << ") Out Of Range";
            throw s.str();
        }
        return buf[index];
    }

    const int& operator[](int index) const {
        if(!in_bounds(index))
        {
            std::ostringstream s;
            s << "Exception operator[](" << len << ") Out Of Range";
            throw s.str();
        }
        return buf[index];
    }

    void fill(int val)
    {
        for(int i = 0; i < len; i++)
            buf[i] = val;
    }

    void copy(int* src)
    {
        if(len != 0)
        {
            int i;
            for(i = 0; i < len; ++i)
                buf[i] = src[i];
        }
    }

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
