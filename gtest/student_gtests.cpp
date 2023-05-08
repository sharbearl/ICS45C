#include <gtest/gtest.h>
#include <sstream>

#include "list.hpp"

using namespace std;
using list::Node;

TEST(ListTests, FromStringBasic) {
    Node* const foo_list_head = list::from_string("foo");
    Node* foo_list = foo_list_head;

    EXPECT_EQ(foo_list->data, 'f');
    // ASSERT instead of EXPECT means: end the test here if this fails, do not try to continue
    // running. This is useful to prevent early crashes.
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_EQ(foo_list->next, nullptr);

    list::free(foo_list_head);
}

TEST(ListTests, Length) {
    Node* const head = list::from_string("foo");
    EXPECT_EQ(list::length(head), 3);
    list::free(head);
}

// Add remaining tests below. All tests should follow
// the format of `TEST(ListTests, <TestName>){}`.

TEST(ListTests, Print) {
    Node* const head = list::from_string("foo");
    stringstream out;
    list::print(out, head);
    EXPECT_STREQ(out.str().c_str(), "foo");

    list::free(head);
}

TEST(ListTest, Compare) {
    Node* const first = list::from_string("abc");
    Node* const second = list::from_string("abcd");
    Node* const third = list::from_string("xyz");
    Node* const fourth = list::from_string("");

    EXPECT_LT(compare(first, second), 0);
    EXPECT_GT(compare(third, first), 0);
    EXPECT_GT(compare(first, fourth), 0);
    EXPECT_EQ(compare(first, first), 0);

    list::free(first);
    list::free(second);
    list::free(third);
    list::free(fourth);
}

TEST(ListTest, CompareInt) {
    Node* const first = list::from_string("abc");
    Node* const second = list::from_string("abcd");
    Node* const third = list::from_string("xyz");
    Node* const fourth = list::from_string("");

    EXPECT_LT(compare(first, second, 4), 0);
    EXPECT_GT(compare(third, first, 3), 0);
    EXPECT_GT(compare(first, fourth, 1), 0);
    EXPECT_EQ(compare(first, first, 3), 0);
    EXPECT_EQ(compare(first, second, 2), 0);

    list::free(first);
    list::free(second);
    list::free(third);
    list::free(fourth);
}
/*
TEST(ListTest, Reverse) {
    Node* const first = list::from_string("abc");
    Node* const second = list::from_string("happy");

    Node* const first_reverse = list::reverse(first);
    Node* const second_reverse = list::reverse(second);

    EXPECT_EQ(compare(first_reverse, list::from_string("cba")), 0);
    EXPECT_EQ(compare(second_reverse, list::from_string("yppah")), 0);

    list::free(first);
    list::free(second);
    list::free(first_reverse);
    list::free(second_reverse);
}*/

TEST(ListTest, Index) {
    Node* const head = list::from_string("abc");
    Node* const a = new Node{'a', nullptr};
    Node* const z = new Node{'z', nullptr};
 

    EXPECT_EQ(list::index(head, a), 0);
    EXPECT_EQ(list::index(head, z), -1);

    list::free(head);
    delete a;
    delete z;
}
