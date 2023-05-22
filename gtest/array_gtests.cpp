#include <gtest/gtest.h>

#include <string>

#include "array.hpp"

using namespace std;

TEST(ArrayTests, Length) {
    Array<int> arr{3};
    EXPECT_EQ(arr.length(), 3);

    Array<string> arr2{10};
    EXPECT_EQ(arr2.length(), 10);

    EXPECT_EQ(Array<double>{}.length(), 0);
}

TEST(ArrayTests, Subscript) {
    Array<int> arr1{3};
    arr1[0] = 3;
    arr1[2] = 5;
    EXPECT_EQ(arr1[0], 3);
    EXPECT_EQ(arr1[2], 5);

    Array<string> arr2{3};
    arr2[0] = "hello";
    arr2[2] = "world";
    EXPECT_EQ(arr2[0], "hello");
    EXPECT_EQ(arr2[2], "world");

    Array<double> arr3{3};
    arr3[0] = 3.1;
    arr3[2] = 5.2;
    EXPECT_EQ(arr3[0], 3.1);
    EXPECT_EQ(arr3[2], 5.2);
}
