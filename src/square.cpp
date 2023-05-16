#include "square.hpp"

Square::Square(Point center, std::string name, int width) :
    Rectangle(center, name, width, width) {}

double Square::area() const
{
    return Rectangle::area();
}
void Square::draw(std::ostream& out) const
{
    Rectangle::draw(out);
}

Square* Square::clone() const
{
    Square *temp = new Square(*this);
    return temp;
}
