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

TEST(ListTests, Copy) {
    Node* const foo_list_head = list::from_string("foo");
    Node* const foo_list_copy = list::copy(foo_list_head);
    Node* foo_list = foo_list_copy;

    EXPECT_EQ(foo_list->data, 'f');
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_NE(foo_list->next, nullptr);

    foo_list = foo_list->next;
    EXPECT_EQ(foo_list->data, 'o');
    ASSERT_EQ(foo_list->next, nullptr);

    list::free(foo_list_head);
    list::free(foo_list_copy);
}

TEST(ListTests, Compare) {
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

TEST(ListTests, CompareInt) {
    Node* const first = list::from_string("abc");
    Node* const second = list::from_string("abcd");
    Node* const third = list::from_string("xyz");
    Node* const fourth = list::from_string("");

    EXPECT_LT(list::compare(first, second, 4), 0);
    EXPECT_GT(list::compare(third, first, 3), 0);
    EXPECT_GT(list::compare(first, fourth, 1), 0);
    EXPECT_EQ(list::compare(first, first, 3), 0);
    EXPECT_EQ(list::compare(first, second, 2), 0);

    list::free(first);
    list::free(second);
    list::free(third);
    list::free(fourth);
}

TEST(ListTests, Reverse) {
    Node* const first = list::from_string("abc");
    Node* const second = list::from_string("happy");

    Node* const first_reverse = list::reverse(first);
    Node* const second_reverse = list::reverse(second);

    Node* const first_check = list::from_string("cba");
    Node* const second_check = list::from_string("yppah");

    EXPECT_EQ(list::compare(first_reverse, first_check), 0);
    EXPECT_EQ(list::compare(second_reverse, second_check), 0);

    list::free(first);
    list::free(second);
    list::free(first_reverse);
    list::free(second_reverse);
    list::free(first_check);
    list::free(second_check);
}

TEST(ListTests, Append) {
    Node* const first = list::from_string("abc");
    Node* const second = list::from_string("def");
    Node* const third = list::from_string("");

    Node* const one = list::append(first, second);
    Node* const two = list::append(first, third);
    Node* const three = list::append(third, first);

    Node* const check = list::from_string("abcdef");

    EXPECT_EQ(list::compare(one, check), 0);
    EXPECT_EQ(list::compare(two, first), 0);
    EXPECT_EQ(list::compare(three, first), 0);

    list::free(first);
    list::free(second);
    list::free(third);
    list::free(one);
    list::free(two);
    list::free(three);
    list::free(check);

}

TEST(ListTests, Index) {
    Node* const head = list::from_string("abc");
    Node* a = list::nth(head, 0);
    Node* c = list::nth(head, 2);
 

    EXPECT_EQ(list::index(head, a), 0);
    EXPECT_EQ(list::index(head, c), 2);

    list::free(head);
}

TEST(ListTests, FindChar) {
    Node* const head = list::from_string("abc");

    Node* one = list::find_char(head, 'a');
    Node* two = list::find_char(head, 'b');
    Node* three = list::find_char(head, 'c');
    Node* four = list::find_char(head, 's');
    Node* five = list::find_char(head, '\0');

    EXPECT_EQ(one->data, 'a');
    EXPECT_EQ(two->data, 'b');
    EXPECT_EQ(three->data, 'c');
    EXPECT_EQ(four, nullptr);
    EXPECT_EQ(five, nullptr);

    list::free(head);
}

TEST(ListTests, FindList) {
    Node* const head = list::from_string("abcdefg");

    Node* const one = list::from_string("");
    Node* first = list::find_list(head, one);
    EXPECT_EQ(first, head);

    Node* const two = list::from_string("abc");
    Node* second = list::find_list(head, two);
    EXPECT_EQ(second->data, 'a');

    Node* const three = list::from_string("efg");
    Node* third = list::find_list(head, three);
    EXPECT_EQ(third->data, 'e');

    Node* const four = list::from_string("cde");
    Node* fourth = list::find_list(head, four);
    EXPECT_EQ(fourth->data, 'c');

    Node* const five = list::from_string("abe");
    Node* fifth = list::find_list(head, five);
    EXPECT_EQ(fifth, nullptr);
 
    Node* const six = list::from_string("xyz");
    Node* sixth = list::find_list(head, six);
    EXPECT_EQ(sixth, nullptr);

    list::free(head);
    list::free(one);
    list::free(two);
    list::free(three);
    list::free(four);
    list::free(five);
    list::free(six);
}

TEST(ListTests, Nth) { 
    Node* const head = list::from_string("abc");

    Node* first = list::nth(head, 0);
    Node* second = list::nth(head, 1);
    Node* third = list::nth(head, 2);
    Node* fourth = list::nth(head, 3);

    EXPECT_EQ(first->data, 'a');
    EXPECT_EQ(second->data, 'b');
    EXPECT_EQ(third->data, 'c');
    EXPECT_EQ(fourth, nullptr);


    list::free(head);
}

TEST(ListTests, Last) {
    Node* const first = list::from_string("abc");
    Node* last_one = list::last(first);
    EXPECT_EQ(last_one->data, 'c');

    Node* const second = list::from_string("happy");
    Node* last_two = list::last(second);
    EXPECT_EQ(last_two->data, 'y');

    list::free(first);
    list::free(second);
}
