#include "Point.hpp"

static Fixed   abs(Fixed x) {
    if (x < 0)
        return x * -1;
    return x;
}

static Fixed area(Point const a, Point const b, Point const c) {
    return (
        abs((
            a.getX() * (b.getY() - c.getY())) +
            (b.getX() * (c.getY() - a.getY())) +
            (c.getX() * (a.getY() - b.getY()))
        ));
}
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed abc = area(a, b, c);
    Fixed pab = area(point, b, c);
    Fixed pbc = area(a, point, c);
    Fixed pac = area(a, b, point);
    return (abc == pab + pbc + pac);
}

