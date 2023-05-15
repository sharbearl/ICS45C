#include "circle.hpp"
#include <iostream>
#include <numbers>

Circle::Circle(Point center, std::string name, int radius) : 
    Shape(center, name), radius(radius) {}

Circle* Circle::clone()
{
    return Circle(this);
}

double Circle::area() const override
{
    return 0.0;
}

void Circle::draw(std::ostream& out) const override
{

}
