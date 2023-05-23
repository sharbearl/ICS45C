#include <gtest/gtest.h>

#include <string>

#include "matrix.hpp"

using namespace std;

TEST(MatrixTests, RowsAndCols) {
    Matrix<int> mat{3, 2};
    EXPECT_EQ(mat.num_rows(), 3);
    EXPECT_EQ(mat.num_cols(), 2);

    Matrix<double> mat2{5, 1};
    EXPECT_EQ(mat2.num_rows(), 5);
    EXPECT_EQ(mat2.num_cols(), 1);

    Matrix<string> mat3;
    EXPECT_EQ(mat3.num_rows(), 0);
    EXPECT_EQ(mat3.num_cols(), 0);
}

TEST(MatrixTests, Subscript) {
    Matrix<int> mat1{3, 2};
    mat1[0][0] = 0;
    mat1[2][1] = 2;
    EXPECT_EQ(mat1[0][0], 0);
    EXPECT_EQ(mat1[2][1], 2);

    Matrix<double> mat2{3, 2};
    mat2[0][0] = 0.5;
    mat2[2][1] = 2.3;
    EXPECT_EQ(mat2[0][0], 0.5);
    EXPECT_EQ(mat2[2][1], 2.3);

    Matrix<string> mat3{3, 2};
    mat3[0][0] = "hello";
    mat3[2][1] = "world";
    EXPECT_EQ(mat3[0][0], "hello");
    EXPECT_EQ(mat3[2][1], "world");
}

TEST(MatrixTests, OutOfBounds) {
    Array<int> arr1{1};
    EXPECT_ANY_THROW(arr1[11]);

    Array<double> arr2{1};
    EXPECT_ANY_THROW(arr2[11]);

    Array<string> arr3{1};
    EXPECT_ANY_THROW(arr3[11]);
}
