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
    char a[10] = "abc";
    char b[10] = "xyz"; 
    String::reverse_cpy(a, b);
    EXPECT_STREQ(a, "zyx");

    char result[10] = "code";
    String::reverse_cpy(result, result);
    EXPECT_STREQ(result, "edoc"); 
}

TEST(StringFunction, strchr) {
    char a[10] = "abcdcba";

    EXPECT_TRUE(String::strchr(a, 'b'));
    EXPECT_FALSE(String::strchr(a, 'z'));
}

TEST(StringFunction, strstr) {
    EXPECT_TRUE(false); 
}
