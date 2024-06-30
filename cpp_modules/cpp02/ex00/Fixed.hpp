

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
private:
    int _num;
    static const int _bits = 8;

public:
    Fixed(void);
    Fixed(Fixed const &cpy);
    Fixed &operator=(Fixed const &cpy);
    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif