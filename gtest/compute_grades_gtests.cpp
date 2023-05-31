#include <gtest/gtest.h>
#include <sstream>

#include "compute_grades.hpp"

using namespace std;

TEST(StudentTests, Output) {
    Student s;
    stringstream in{"Name Lisa Simpson\nQuiz 100 100 10 100\nHW   100 100 100 100\nFinal 100\n\n"};
    stringstream out;
    in >> s;
    s.validate();
    s.compute_grade();
    out << s;
    EXPECT_EQ(out.str(), "Name:   Lisa Simpson\nHW Ave: 100\nQZ Ave: 100\nFinal:  100\nTotal:  100\nGrade:  A+\n");
}

TEST(StudentTests, Validate) {
    Student s;
    stringstream in{"Quiz 1000"};
    in >> s;
    EXPECT_ANY_THROW(s.validate());
}

