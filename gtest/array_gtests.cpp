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

TEST(ArrayTests, Print) {
    stringstream out1;

    Array<int> arr1{3};
    arr1[0] = 0;
    arr1[1] = 1;
    arr1[2] = 2;
    out1 << arr1;
    EXPECT_EQ(out1.str(), "       0       1       2");

    stringstream out2;

    Array<string> arr2{3};
    arr2[0] = "one";
    arr2[1] = "two";
    arr2[2] = "three";
    out2 << arr2;
    EXPECT_EQ(out2.str(), "     one     two   three");

    stringstream out3;

    Array<double> arr3{3};
    arr3[0] = 1.1;
    arr3[1] = 2.2;
    arr3[2] = 3.3;
    out3 << arr3;
    EXPECT_EQ(out3.str(), "    1.10    2.20    3.30");
}

TEST(ArrayTests, Read) {
    stringstream in1{"1 2 3 4"};

    Array<int> arr1{3};
    in1 >> arr1;
    EXPECT_EQ(arr1[0], 1);
    EXPECT_EQ(arr1[1], 2);
    EXPECT_EQ(arr1[2], 3);

    stringstream in2{"1.1 2.2 3.3 4.4"};

    Array<double> arr2{3};
    in2 >> arr2;
    EXPECT_EQ(arr2[0], 1.1);
    EXPECT_EQ(arr2[1], 2.2);
    EXPECT_EQ(arr2[2], 3.3);

    stringstream in3{"one two three four"};

    Array<string> arr3{3};
    in3 >> arr3;
    EXPECT_EQ(arr3[0], "one");
    EXPECT_EQ(arr3[1], "two");
    EXPECT_EQ(arr3[2], "three");
}
