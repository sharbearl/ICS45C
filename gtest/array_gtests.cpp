#include <gtest/gtest.h>

#include <string>

#include "alloc.hpp"
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

TEST(ArrayTests, Fill) {
    Array<int> arr1{5};
    arr1.fill(20);
    EXPECT_EQ(arr1[0], 20);
    arr1.fill(5);
    EXPECT_EQ(arr1[4], 5);

    Array<string> arr2{5};
    arr2.fill("two");
    EXPECT_EQ(arr2[0], "two");
    arr2.fill("five");
    EXPECT_EQ(arr2[4], "five");

    Array<double> arr3{5};
    arr3.fill(2.2);
    EXPECT_EQ(arr3[0], 2.2);
    arr3.fill(5.5);
    EXPECT_EQ(arr3[4], 5.5);
}

TEST(ArrayTests, OutOfBounds) {
    Array<int> arr1{1};
    EXPECT_ANY_THROW(arr1[11]);

    Array<string> arr2{1};
    EXPECT_ANY_THROW(arr2[11]);

    Array<double> arr3{1};
    EXPECT_ANY_THROW(arr3[11]);
}

TEST(ArrayTests, CopyConstructor) {
    Array<int> arr1{10};
    arr1.fill(20);
    Array<int> arr2{arr1};
    EXPECT_EQ(arr2.length(), 10);
    EXPECT_EQ(arr2[0], 20);
    EXPECT_EQ(arr2[9], 20);

    Array<int> empty;
    Array arr3{empty};
    EXPECT_EQ(arr3.length(), 0);

    Array<double> arr4{5};
    arr4.fill(2.2);
    Array<double> arr5{arr4};
    EXPECT_EQ(arr5.length(), 5);
    EXPECT_EQ(arr5[0], 2.2);
    EXPECT_EQ(arr5[4], 2.2);

    Array<string> arr6{5};
    arr6.fill("one");
    Array<string> arr7{arr6};
    EXPECT_EQ(arr7.length(), 5);
    EXPECT_EQ(arr7[0], "one");
    EXPECT_EQ(arr7[4], "one");
}

TEST(ArrayTests, MoveConstructor) {
    AllocationTracker tracker;

    Array<int> arr{10};
    arr.fill(20);

    std::size_t allocs_before_move = tracker.get_num_allocations();
    Array<int> arr2{std::move(arr)};
    std::size_t allocs_after_move = tracker.get_num_allocations();

    EXPECT_EQ(allocs_before_move, allocs_after_move);

    EXPECT_EQ(arr2.length(), 10);
    EXPECT_EQ(arr2[0], 20);
    EXPECT_EQ(arr2[9], 20);

    Array<double> empty;
    Array arr3{std::move(empty)};
    EXPECT_EQ(arr3.length(), 0);
}

TEST(ArrayTests, Swap) {
    AllocationTracker tracker;

    Array<int> arr{10};
    arr.fill(20);
    Array<int> arr2{2};
    arr2.fill(5);

    std::size_t allocs_before_swap = tracker.get_num_allocations();
    swap(arr, arr2);
    std::size_t allocs_after_swap = tracker.get_num_allocations();

    EXPECT_EQ(allocs_before_swap, allocs_after_swap);

    EXPECT_EQ(arr2.length(), 10);
    EXPECT_EQ(arr2[0], 20);
    EXPECT_EQ(arr2[9], 20);

    EXPECT_EQ(arr.length(), 2);
    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[1], 5);
}

TEST(ArrayTests, CopyAssignment) {
    Array<int> arr{10};
    arr.fill(20);

    Array<int> arr2{2};
    arr2.fill(5);

    arr = arr2;

    EXPECT_EQ(arr.length(), 2);
    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[1], 5);

    EXPECT_EQ(arr2.length(), 2);
    EXPECT_EQ(arr2[0], 5);
    EXPECT_EQ(arr2[1], 5);

    arr = arr;

    EXPECT_EQ(arr.length(), 2);
    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[1], 5);
    
    Array<double> arr3{10};
    arr3.fill(1.1);

    Array<double> arr4{2};
    arr4.fill(2.2);

    arr3 = arr4;

    EXPECT_EQ(arr3.length(), 2);
    EXPECT_EQ(arr3[0], 2.2);
    EXPECT_EQ(arr3[1], 2.2);

    Array<string> arr5{10};
    arr5.fill("one");

    Array<string> arr6{2};
    arr6.fill("two");
/*
    arr5 = arr6;

    EXPECT_EQ(arr5.length(), 2);
    EXPECT_EQ(arr5[0], "two");
    EXPECT_EQ(arr5[1], "two");*/
}

TEST(ArrayTests, MoveAssignment) {
    AllocationTracker tracker;

    Array<int> arr{10};
    arr.fill(20);

    Array<int> arr2{2};
    arr2.fill(5);

    std::size_t allocs_before_move = tracker.get_num_allocations();
    arr = std::move(arr2);
    std::size_t allocs_after_move = tracker.get_num_allocations();
    EXPECT_EQ(allocs_before_move, allocs_after_move);

    EXPECT_EQ(arr.length(), 2);
    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[1], 5);
}

