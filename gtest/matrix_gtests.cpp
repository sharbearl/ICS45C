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
    Matrix<int> mat1{1, 1};
    EXPECT_ANY_THROW(mat1[11][1]);

    Matrix<double> mat2{1, 1};
    EXPECT_ANY_THROW(mat2[11][1]);

    Matrix<string> mat3{1, 1};
    EXPECT_ANY_THROW(mat3[11][1]);
}

TEST(MatrixTests, Fill) {
    Matrix<int> mat1{3, 2};
    mat1.fill(5);
    EXPECT_EQ(mat1[0][0], 5);
    EXPECT_EQ(mat1[2][1], 5);

    Matrix<double> mat2{3, 2};
    mat2.fill(1.1);
    EXPECT_EQ(mat2[0][0], 1.1);
    EXPECT_EQ(mat2[2][1], 1.1);

    Matrix<string> mat3{3, 2};
    mat3.fill("hello");
    EXPECT_EQ(mat3[0][0], "hello");
    EXPECT_EQ(mat3[2][1], "hello");
}

TEST(MatrixTests, FillFn) {
    Matrix<int> mat1{3, 2};
    mat1.fill_with_fn([](int i, int j) { return i * j; });
    EXPECT_EQ(mat1[0][0], 0);
    EXPECT_EQ(mat1[2][1], 2);

    Matrix<double> mat2{3, 2};
    mat2.fill_with_fn([](int i, int j) { return (i*1.0) + (j*0.1); });
    EXPECT_EQ(mat2[0][0], 0.0);
    EXPECT_EQ(mat2[2][1], 2.1);

    Matrix<string> mat3{3, 2};
    mat3.fill_with_fn([](int i, int j) 
        { return (to_string(i)) + to_string(j); });
    EXPECT_EQ(mat3[0][0], "00");
    EXPECT_EQ(mat3[2][1], "21");
}

TEST(MatrixTests, Print)
{
    stringstream out1;
    Matrix<int> mat1{3, 2};
    mat1.fill_with_fn([](int i, int j) { return i * j; });
    out1 << mat1; 
    EXPECT_EQ(out1.str(), "       0       0\n       0       1\n       0       2\n");

    stringstream out2;
    Matrix<double> mat2{3, 2};
    mat2.fill_with_fn([](int i, int j) { return (i*1.0) + (j*0.1); });
    out2 << mat2;
    EXPECT_EQ(out2.str(), "    0.00    0.10\n    1.00    1.10\n    2.00    2.10\n");
    
    stringstream out3;
    Matrix<string> mat3{3, 2};
    mat3.fill_with_fn([](int i, int j) 
        { return (to_string(i)) + to_string(j); });
    out3 << mat3;
    EXPECT_EQ(out3.str(), "      00      01\n      10      11\n      20      21\n");
}

TEST(MatrixTests, Read)
{
    stringstream in1{"1 2 3 4 5 6 7"};

    Matrix<int> mat1{3, 2};
    in1 >> mat1;
    EXPECT_EQ(mat1[0][0], 1);
    EXPECT_EQ(mat1[0][1], 2);
    EXPECT_EQ(mat1[2][1], 6);

    stringstream in2{"1.1 2.2 3.3 4.4 5.5 6.6 7.7"};

    Matrix<double> mat2{3, 2};
    in2 >> mat2;
    EXPECT_EQ(mat2[0][0], 1.1);
    EXPECT_EQ(mat2[0][1], 2.2);
    EXPECT_EQ(mat2[2][1], 6.6);

    stringstream in3{"one two three four five six seven"};

    Matrix<string> mat3{3, 2};
    in3 >> mat3;
    EXPECT_EQ(mat3[0][0], "one");
    EXPECT_EQ(mat3[0][1], "two");
    EXPECT_EQ(mat3[2][1], "six");
}
