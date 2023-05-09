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

TEST(StringClass, InBounds) {
    String s("test"), t("");

    EXPECT_TRUE(s.in_bounds(0));
    EXPECT_TRUE(s.in_bounds(3));
    EXPECT_FALSE(s.in_bounds(10));

    EXPECT_FALSE(t.in_bounds(0));
    EXPECT_FALSE(t.in_bounds(3));
}

TEST(StringClass, Reverse) {
    String s("abc"), t("happy");

    EXPECT_EQ(s.reverse(), String("cba"));
    EXPECT_EQ(t.reverse(), String("yppah"));
}

TEST(StringClass, Indexing) {
    String s("abc"), t("");

    EXPECT_EQ(s[0], 'a');
    EXPECT_EQ(s[1], 'b');
    EXPECT_EQ(s[2], 'c');
    EXPECT_EQ(s[4], 'a');
    EXPECT_EQ(t[0], '@');
    EXPECT_EQ(t[4], '@');
}

TEST(StringClass, IndexChar) {
    String s("abcdefg");

    EXPECT_EQ(s.indexOf('a'), 0);
    EXPECT_EQ(s.indexOf('d'), 3);
    EXPECT_EQ(s.indexOf('g'), 6);
    EXPECT_EQ(s.indexOf('z'), -1);
}

TEST(StringClass, IndexStr) {
    String s("abcdefg");
    EXPECT_EQ(s.indexOf(String("abc")), 0);
    EXPECT_EQ(s.indexOf(String("cde")), 2);
    EXPECT_EQ(s.indexOf(String("efg")), 4);
    EXPECT_EQ(s.indexOf(String("xyz")), -1);
    EXPECT_EQ(s.indexOf(String("")), -1);

    String t("");
    EXPECT_EQ(t.indexOf(String("abc")), -1);
    EXPECT_EQ(t.indexOf(String("")), 0);
}

TEST(StringClass, Concatenate) {
    String s("abc"), t("def");

    EXPECT_EQ(s+t, String("abcdef"));
    EXPECT_EQ(s+s, String("abcabc"));

    s += t;
    EXPECT_EQ(s, String("abcdef"));
}
