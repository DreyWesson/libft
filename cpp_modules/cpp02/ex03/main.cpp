#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
    Point a(0, 0);
    Point b(20, 0);
    Point c(10, 30);
    Point point_inside(10, 30);
    Point point_outside(3, 20);

    std::cout << "Point is " << (bsp(a, b, c, point_inside) ? "Inside" : "Outside") << std::endl;
    std::cout << "Point is " << (bsp(a, b, c, point_outside) ? "Inside" : "Outside") << std::endl;
    return 0;
}