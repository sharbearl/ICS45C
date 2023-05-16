#include <gtest/gtest.h>

#include <sstream>

#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "triangle.hpp"

TEST(CircleTests, Area) {
    EXPECT_NEAR(Circle({1, 2}, "", 3).area(), 28.27, 0.01);
}

TEST(CircleTests, Draw) {
    Circle c{{5, 10}, "circle", 3};

    std::stringstream out;
    c.draw(out);

    EXPECT_STREQ(out.str().c_str(),
                 "   *   \n"
                 " ***** \n"
                 " ***** \n"
                 "   *   \n");
}

TEST(CircleTests, Print) {
    Circle c{{3, 2}, "foo", 10};

    std::stringstream out;
    c.print(out);

    EXPECT_STREQ(out.str().c_str(), "foo at (3, 2) area = 314.159\n");
}

TEST(CircleTests, Clone) {
    Circle c{{3, 2}, "foo", 10};

    Circle* clone = c.clone();
    std::stringstream out;
    clone->print(out);

    EXPECT_STREQ(out.str().c_str(), "foo at (3, 2) area = 314.159\n");
    delete clone;
}

TEST(RectangleTests, Area) {
    EXPECT_EQ(Rectangle({1, 2}, "", 2, 2).area(), 4.0);
}

TEST(RectangleTests, Draw) {
    Rectangle r{{0, 0}, "rectangle", 4, 3};

    std::stringstream out;
    r.draw(out);

    EXPECT_STREQ(out.str().c_str(),
                 "****\n"
                 "****\n");
}

TEST(RectangleTests, Print) {
    Rectangle r{{3, 2}, "foo", 10, 10};

    std::stringstream out;
    r.print(out);

    EXPECT_STREQ(out.str().c_str(), "foo at (3, 2) area = 100\n");
}

TEST(RectangleTests, Clone) {
    Rectangle r{{3, 2}, "foo", 10, 10};                           

    Rectangle* clone = r.clone();
    std::stringstream out;
    clone->print(out);

    EXPECT_STREQ(out.str().c_str(), "foo at (3, 2) area = 100\n");
    delete clone;
}

TEST(TriangleTests, Area) {
    EXPECT_EQ(Triangle({1, 2}, "", 2, 2).area(), 2.0);
}

TEST(TriangleTests, Draw) {
    Triangle t{{0, 0}, "triangle", 4, 3};

    std::stringstream out;
    t.draw(out);

    EXPECT_STREQ(out.str().c_str(),
                 "  *\n"
                 " ***\n");
}

TEST(TriangleTests, Print) {
    Triangle t{{3, 2}, "foo", 10, 10};

    std::stringstream out;
    t.print(out);

    EXPECT_STREQ(out.str().c_str(), "foo at (3, 2) area = 50\n");
}

TEST(TriangleTests, Clone) {
    Triangle t{{3, 2}, "foo", 10, 10};                           

    Triangle* clone = t.clone();
    std::stringstream out;
    clone->print(out);

    EXPECT_STREQ(out.str().c_str(), "foo at (3, 2) area = 50\n");
    delete clone;
}

TEST(SquareTests, Area) {
    EXPECT_EQ(Square({1, 2}, "", 2).area(), 4.0);
}

TEST(SquareTests, Draw) {
    Square s{{0, 0}, "square", 4};

    std::stringstream out;
    s.draw(out);

    EXPECT_STREQ(out.str().c_str(),
                 "****\n"
                 "****\n");
}

TEST(SquareTests, Print) {
    Square s{{3, 2}, "foo", 10};

    std::stringstream out;
    s.print(out);

    EXPECT_STREQ(out.str().c_str(), "foo at (3, 2) area = 100\n");
}

TEST(SquareTests, Clone) {
    Square s{{3, 2}, "foo", 10};                           

    Square* clone = s.clone();
    std::stringstream out;
    clone->print(out);

    EXPECT_STREQ(out.str().c_str(), "foo at (3, 2) area = 100\n");
    delete clone;
}

