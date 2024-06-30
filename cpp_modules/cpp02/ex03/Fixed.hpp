

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
    ~Fixed(void);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;
    /**
     * Overloaded comparison operators
    */
    Fixed &operator=(Fixed const &cpy);
    bool operator==(Fixed const &cpy) const;
    bool operator>(Fixed const &cpy) const;
    bool operator>=(Fixed const &cpy) const;
    bool operator<(Fixed const &cpy) const;
    bool operator<=(Fixed const &cpy) const;
    bool operator!=(Fixed const &cpy) const;
    /**
     * Overloaded arithmetic operators
    */
    Fixed operator+(Fixed const &cpy) const;
    Fixed operator-(Fixed const &cpy) const;
    Fixed operator*(Fixed const &cpy) const;
    Fixed operator/(Fixed const &cpy) const;
    /**
     * Public overloaded member function
    */    
    static Fixed& min(Fixed &a, Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);
    /**
     * Increment and Decrement
    */
    Fixed&  operator++(void);
    Fixed   operator++(int);
    Fixed&  operator--(void);
    Fixed   operator--(int);
};
/**
 * Overloaded Insertion Operator
*/
std::ostream & operator<<(std::ostream &cout, Fixed const & i);

#endif