#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "rectangle.hpp"

class Square : public Rectangle {
public:
    Square(Point center, std::string name, int width);

    double area() const override;
    void draw(std::ostream& out) const override;
    Square* clone() const override;

protected:
    Square(const Square& other) = default;

};

#endif
