#include "circle.hpp"
#include <iostream>
#include <numbers>

Circle::Circle(Point center, std::string name, int radius) : 
    Shape(center, name), radius(radius) {}

Circle* Circle::clone() const
{
    Circle temp = Circle(*this);
    return &temp;
}

double Circle::area() const
{
    return 0.0;
}

void Circle::draw(std::ostream& out) const
{

}
