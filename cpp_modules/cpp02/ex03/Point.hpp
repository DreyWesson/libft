#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

enum PointLocation { INSIDE, OUTSIDE, ON_EDGE };

class Point
{
private:
    const Fixed _x;
    const Fixed _y;

public:
    Point(void);
    ~Point(void);
    Point(float const x, float const y);
    Point(const Point &cpy);

    Point &operator=(const Point &cpy);

    Fixed getX(void) const;
    Fixed getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif