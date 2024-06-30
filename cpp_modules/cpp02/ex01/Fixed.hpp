

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _num;
    static const int _fractional_bits = 8;

public:
    Fixed(void);
    Fixed(int const num);
    Fixed(float const num);
    Fixed(Fixed const &cpy);
    Fixed &operator=(Fixed const &cpy);
    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream & operator<<(std::ostream &cout, Fixed const & i);

#endif