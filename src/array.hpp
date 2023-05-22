#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>

template <typename T>
class Array {
public:
    Array() : len{0}, buf{nullptr} {}

    explicit Array(int len) : len{len}, buf{new T[len]} {}
    /*
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
            delete buf;
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
*/
    ~Array() 
    {
        delete[] buf;
    }

    int length() const {
        return len;
    }

    T& operator[](int index) {
        if(!in_bounds(index))
        {
            std::ostringstream s;
            s << "Exception operator[](" << len << ") Out Of Range";
            throw s.str();
        }
        return buf[index];
    }

    const T& operator[](int index) const {
        if(!in_bounds(index))
        {
            std::ostringstream s;
            s << "Exception operator[](" << len << ") Out Of Range";
            throw s.str();
        }
        return buf[index];
    }

    void fill(T val)
    {
        for(int i = 0; i < len; i++)
            buf[i] = val;
    }
/*
    void copy(int* src)
    {
        if(len != 0)
        {
            int i;
            for(i = 0; i < len; ++i)
                buf[i] = src[i];
        }
    }
    */
    template <typename Fn>
    void fill_with_fn(Fn fn);

private:
    int len;
    T* buf;

    bool in_bounds(int index) const {
        return index >= 0 && index < len;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream&out, const Array<T>& array)
{
    std::stringstream temp;
    temp << std::setprecision(2) << std::fixed << std::right;

    for(int i = 0; i < array.length(); ++i)
    {
        temp << std::setw(8) << array[i];
    }

    out << temp.str();
    return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, Array<T>& array)
{
    for(int i = 0; i < array.length(); ++i)
    {
        in >> array[i];
    }
    return in;
}

#endif
