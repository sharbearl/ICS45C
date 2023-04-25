#include <gtest/gtest.h>

#include <algorithm>
#include <sstream>

#include "string.hpp"

using namespace std;

TEST(StringClass, Constructors) {
    String s("hello");
    EXPECT_EQ(s.size(), 5);

    String t(s);
    EXPECT_EQ(t.size(), 5);
    EXPECT_EQ(s.size(), 5);
}

TEST(StringClass, Print) {
    String s("foo");
    stringstream out;
    s.print(out);
    EXPECT_STREQ(out.str().c_str(), "foo");

    stringstream out2;
    String().print(out2);
    EXPECT_STREQ(out2.str().c_str(), "");

    stringstream out3;
    out3 << s << s << String("bar");
    EXPECT_STREQ(out3.str().c_str(), "foofoobar");
}

TEST(StringClass, Comparisons) {
    EXPECT_LT(String("aaaa"), String("aaab"));
    EXPECT_LE(String("aaaa"), String("aaab"));
    EXPECT_EQ(String("foo"), String("foo"));
    EXPECT_NE(String("foo"), String("fooo"));
}

TEST(StringClass, Assignment) {
    String s("test"), t("foo");

    s = t;
    EXPECT_EQ(s.size(), t.size());
    EXPECT_EQ(s, t);

    s = s;
    EXPECT_EQ(s.size(), t.size());
    EXPECT_EQ(s, t);

    s = String();
    EXPECT_EQ(s, String());
    EXPECT_EQ(s.size(), 0);
}

TEST(StringClass, Concatenation) {
    String s("abc"), t("def");

    EXPECT_EQ(s+t, String("abcdef"));

    s += t;
    EXPECT_EQ(s, String("abcdef"));
}

TEST(StringClass, Reverse) {
    String s("abcd");
    EXPECT_EQ(s.reverse(), String("dcba"));

    String t("happy");
    EXPECT_EQ(t.reverse(), String("yppah"));
}

TEST(StringClass, IndexOfChar) {
    String s("abcd");
    EXPECT_EQ(s.indexOf('a'), 0);
    EXPECT_EQ(s.indexOf('d'), 3);

    String t("abcdcba");
    EXPECT_EQ(s.indexOf('b'), 1);
    EXPECT_EQ(s.indexOf('z'), -1);
}

TEST(StringClass, IndexOfString) {
    String s("abcd");
    EXPECT_EQ(s.indexOf(String("ab")), 0);
    EXPECT_EQ(s.indexOf(String("cd")), 2);

    String t("abcdcba");
    EXPECT_EQ(s.indexOf(String("bcd")), 1);
    EXPECT_EQ(s.indexOf(String("xyz")), -1);
}
