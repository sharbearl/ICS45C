// ------------------------- Tests File - stack_test.cpp -------------------- //
// This file is for writing your own user tests. Be sure to include your *.h
// files to be able to access the functions that you wrote for unit testing.
// An example has been provided, but more documentation is available here:
// https://github.com/google/googletest/blob/main/docs/primer.md
// -------------------------------------------------------------------------- //

#include <gtest/gtest.h>
#include <string>

#include <iostream>
using namespace std;
// Include all of your *.h files you want to unit test:
#include "letter_count.h"

namespace {

TEST(Count, SimpleString) {
  // Push 'c' on the stack, and make sure we get 'c' back.
  std::string ts = "ABCDEF";
  int char_counts[26] = { 0 };
  count(ts, char_counts);
  for (int i = 0; i < 6; ++i) {
    EXPECT_EQ(1, char_counts[i]);
  }
}

// ADD YOUR TESTS HERE:
TEST(Count, UpperLower) {
    std::string s = "AaZz";
    int char_counts[26] = {0};
    count(s, char_counts);
    EXPECT_EQ(2, char_counts[0]);
    EXPECT_EQ(2, char_counts[25]);
    for (int i = 1; i < 24; ++i) {
        EXPECT_EQ(0, char_counts[i]);
    }
}

TEST(Count, IgnoreOthers) {
    std::string s = "a!";
    int char_counts[26] = {0};
    count(s, char_counts);
    for (int i = 1; i < 26; ++i) {
        EXPECT_EQ(0, char_counts[i]);
    }
}


TEST(Count, MultipleLines) {
    std::string a = "AbCdE";
    std::string b = "aBcDe";
    int char_counts[26] = {0};
    count(a, char_counts);
    count(b, char_counts);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(2, char_counts[i]);
    }
}

TEST(Count, Output) {
    std::string a = "AbCdE";
    int char_counts[26] = {0};
    count(a, char_counts);
    testing::internal::CaptureStdout();
    print_counts(char_counts, 26);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_STREQ("A 1\nB 1\nC 1\nD 1\nE 1\nF 0\nG 0\nH 0\nI 0\nJ 0\nK 0\nL 0\nM 0\nN 0\nO 0\nP 0\nQ 0\nR 0\nS 0\nT 0\nU 0\nV 0\nW 0\nX 0\nY 0\nZ 0\n", output.c_str());
}

} // anonymous namespace
