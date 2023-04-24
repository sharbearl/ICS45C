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
    EXPECT_TRUE(false);
}

TEST(StringFunction, strncat) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strcmp) {
    char a[10] = "abc";
    char b[10] = "xyz";
    char c[10] = "abcdefghi";
    EXPECT_EQ(String::strcmp(a,b), -1);
    EXPECT_EQ(String::strcmp(b,a), 1);
    EXPECT_EQ(String::strcmp(a,a), 0);
    EXPECT_EQ(String::strcmp(c,c), 0);
    EXPECT_EQ(String::strcmp(a,c), -1);
}

TEST(StringFunction, strncmp) {
    char a[10] = "abc";
    char b[10] = "xyz";
    char c[10] = "abcdefghi";
    EXPECT_EQ(String::strncmp(a,b,3), -1);
    EXPECT_EQ(String::strncmp(b,a,3), 1);
    EXPECT_EQ(String::strncmp(a,a,2), 0);
    EXPECT_EQ(String::strncmp(a,c,3), 0);
    EXPECT_EQ(String::strncmp(a,c,5), -1);
}

TEST(StringFunction, reverse_cpy) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strchr) {
    EXPECT_TRUE(false);
}

TEST(StringFunction, strstr) {
    EXPECT_TRUE(false);
}
