#include "Fixed.hpp"

// void debugger(void) {
//     // Test the 4 arithmetic operators
//     Fixed a(5.5f);
//     Fixed b(2.2f);

//     Fixed sum = a + b;
//     Fixed difference = a - b;
//     Fixed product = a * b;
//     Fixed quotient = a / b;

//     std::cout << "Sum: " << sum << std::endl;
//     std::cout << "Difference: " << difference << std::endl;
//     std::cout << "Product: " << product << std::endl;
//     std::cout << "Quotient: " << quotient << std::endl;

//     // Test the four increment and decrement operators
//     Fixed c(10.0f);

//     std::cout << "Original value: " << c << std::endl;

//     Fixed preIncremented = ++c;
//     std::cout << "Pre-incremented: " << preIncremented << std::endl;

//     Fixed postIncremented = c++;
//     std::cout << "Post-incremented: " << postIncremented << std::endl;
//     std::cout << "Final value: " << c << std::endl;

//     // Test the static member functions min() and max()
//     Fixed d(3.3f);
//     Fixed e(4.4f);
//     std::cout << "d: " << d  << ", e: " << e << std::endl;

//     Fixed minResult = Fixed::min(d, e);
//     Fixed maxResult = Fixed::max(d, e);

//     std::cout << "Min value: " << minResult << std::endl;
//     std::cout << "Max value: " << maxResult << std::endl;
// }

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}