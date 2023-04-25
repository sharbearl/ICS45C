#include <gtest/gtest.h>

#include "string.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strncpy) {
    char result[10]; 
    EXPECT_EQ(String::strncpy(result, "foo", 3), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strncpy(result, "foo", 5), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strncpy(result, "foo", 1), result);
    EXPECT_STREQ(result, "f");
}

TEST(StringFunction, strcat) {
    char result[10] = "abc";
    EXPECT_EQ(String::strcat(result, "def"), result);
    EXPECT_STREQ(result, "abcdef");

    EXPECT_EQ(String::strcat(result, "ghi"), result);
    EXPECT_STREQ(result, "abcdefghi");

    EXPECT_EQ(String::strcat(result, ""), result);
    EXPECT_STREQ(result, "abcdefghi");

    char empty[10] = {};
    EXPECT_EQ(String::strcat(empty, "foo"), empty);
    EXPECT_STREQ(empty, "foo");
}

TEST(StringFunction, strncat) {
    char result[10] = "abc";
    EXPECT_EQ(String::strncat(result, "def", 3), result);
    EXPECT_STREQ(result, "abcdef");

    EXPECT_EQ(String::strncat(result, "ghi", 2), result);
    EXPECT_STREQ(result, "abcdefgh");

    EXPECT_EQ(String::strncat(result, "", 2), result);
    EXPECT_STREQ(result, "abcdefgh");

    char empty[10] = {};
    EXPECT_EQ(String::strncat(empty, "foo", 3), empty);
    EXPECT_STREQ(empty, "foo"); 
}

TEST(StringFunction, strcmp) {
    char a[10] = "abc";
    char b[10] = "xyz";
    char c[10] = "abcdefghi";
    EXPECT_LT(String::strcmp(a,b), 0);
    EXPECT_GT(String::strcmp(b,a), 0);
    EXPECT_EQ(String::strcmp(a,a), 0);
    EXPECT_EQ(String::strcmp(c,c), 0);
    EXPECT_LT(String::strcmp(a,c), 0);
}

TEST(StringFunction, strncmp) {
    char a[10] = "abc";
    char b[10] = "xyz";
    char c[10] = "abcdefghi";
    EXPECT_LT(String::strncmp(a,b,3), 0);
    EXPECT_GT(String::strncmp(b,a,3), 0);
    EXPECT_EQ(String::strncmp(a,a,2), 0);
    EXPECT_EQ(String::strncmp(a,c,3), 0);
    EXPECT_LT(String::strncmp(a,c,5), 0);
}

TEST(StringFunction, reverse_cpy) {
    char a[10] = "abc";
    char b[10] = "xyz"; 
    String::reverse_cpy(a, b);
    EXPECT_STREQ(a, "zyx");

    char first[10] = "";
    char second[10] = "code";
    String::reverse_cpy(first, second);
    EXPECT_STREQ(first, "edoc"); 
}

TEST(StringFunction, strchr) {
    char a[10] = "abcdcba";

    EXPECT_NE(String::strchr(a, 'b'), nullptr);
    EXPECT_EQ(*String::strchr(a, 'b'), 'b');

    EXPECT_NE(String::strchr(a, 'd'), nullptr);
    EXPECT_EQ(*String::strchr(a, 'd'), 'd');

    EXPECT_EQ(String::strchr(a, 'z'), nullptr);
}

TEST(StringFunction, strstr) {
    char a[10] = "abcdef";

    EXPECT_NE(String::strstr(a, "a"), nullptr);
    EXPECT_EQ(*String::strstr(a, "a"), 'a');

    EXPECT_NE(String::strstr(a, "abc"), nullptr);
    EXPECT_EQ(*String::strstr(a, "abc"), 'a');

    EXPECT_NE(String::strstr(a, "ef"), nullptr);
    EXPECT_EQ(*String::strstr(a, "ef"), 'e');

    EXPECT_EQ(String::strstr(a, "xyz"), nullptr);
    EXPECT_EQ(String::strstr(a, "abcdefgh"), nullptr);
}
