#include <gtest/gtest.h>
#include <string.h>

#include <algorithm>

#include "string.hpp"
#include "alloc.hpp"

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

TEST(StringFunction, strdup) {
    EXPECT_TRUE(false);
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
    EXPECT_TRUE(false);
}

TEST(StringFunction, strncmp) {
    EXPECT_TRUE(false);
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
