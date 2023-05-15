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

    EXPECT_STREQ(out.str().c_str(), "foo(3, 2)\n");
}

TEST(CircleTests, Clone) {
    Circle c{{3, 2}, "foo", 10};

    Circle* clone = c.clone();
    std::stringstream out;
    clone->print(out);

    EXPECT_STREQ(out.str().c_str(), "foo(3, 2)\n");
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
                 "****\n"
                 "****\n");
}

TEST(RectangleTests, Print) {
    Rectangle r{{3, 2}, "foo", 10, 10};

    std::stringstream out;
    r.print(out);

    EXPECT_STREQ(out.str().c_str(), "foo(3, 2)\n");
}

TEST(RectangleTests, Clone) {
    Rectangle r{{3, 2}, "foo", 10, 10};                           

    Rectangle* clone = r.clone();
    std::stringstream out;
    clone->print(out);

    EXPECT_STREQ(out.str().c_str(), "foo(3, 2)\n");
    delete clone;
}
