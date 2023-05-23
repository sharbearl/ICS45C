#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "array.hpp"

template <typename T>
class Matrix{
public:
    //to be implemented
    Matrix() : rows{0}, cols{0}, data{Array<Array<T>>(0)} {}
    
    Matrix(int rows, int cols) : 
        rows{rows}, cols{cols}, data{Array<Array<T>>(rows)} 
    {
        for(int i = 0; i < rows; ++i)
            data[i] = Array<T>(cols);
    }

    Array<T>& operator[](int row)
    {
        return data[row];
    }

    const Array<T>& operator[](int row) const
    {
        return data[row];
    }

    int num_rows() const
    { return rows; }

    int num_cols() const
    { return cols; }

    void fill(const T& val);

    template <typename Fn>
    void fill_with_fn(Fn fn);

private:
    int rows, cols;
    Array<Array<T>> data;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix);

template <typename T>
std::istream& operator>>(std::istream& in, Matrix<T>& matrix);

#endif
