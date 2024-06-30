#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::~Point(void){}

Point::Point(float const x, float const y) 
: _x(x), _y(y) {}

Point::Point(Point const &cpy): _x(cpy._x), _y(cpy._y) {}

Point & Point::operator=(Point const & val) {
    if (this != &val)
    {
        (Fixed)this->_x = val.getX();
        (Fixed)this->_y = val.getY();
    }
    return *this;
}

Fixed Point::getX(void) const {
    return this->_x;
}

Fixed Point::getY(void) const {
    return this->_y;
}
