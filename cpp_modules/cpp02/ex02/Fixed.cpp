#include "Fixed.hpp"

Fixed::Fixed(void) : _num(0) {}

Fixed::Fixed(int const num) : _num(num * (1 << _fractional_bits)) {}

Fixed::Fixed(float const num) : _num(roundf(num * (1 << _fractional_bits))) {}

Fixed::Fixed(Fixed const &cpy) {
    *this = cpy;
}

Fixed::~Fixed(void) {}

int Fixed::getRawBits(void) const {
    return (this->_num);
}

void Fixed::setRawBits(int const raw) {
    this->_num = raw;
}

int Fixed::toInt( void ) const {
    return (this->_num >> this->_fractional_bits);
}

float Fixed::toFloat( void ) const {
    return ((float)this->_num / (1 << this->_fractional_bits));
}
/**
 * Overloaded Insertion Operators
*/
std::ostream & operator<<(std::ostream &cout, Fixed const & i) {
    cout << i.toFloat();
    return (cout);
}
/**
 * Overloaded Assignment Operators
*/
Fixed & Fixed::operator=(Fixed const & val) {
    if (this != &val)
        this->_num = val.getRawBits();
    return *this;
}
/**
 * Overloaded comparison operators
*/
bool Fixed::operator==(Fixed const &cpy) const {
    return (this->_num == cpy.getRawBits());
}

bool Fixed::operator>(Fixed const &cpy) const {
    return (this->_num > cpy.getRawBits());
}

bool Fixed::operator>=(Fixed const &cpy) const {
    return (this->_num >= cpy.getRawBits());
}

bool Fixed::operator<(Fixed const &cpy) const {
    return (this->_num < cpy.getRawBits());
}

bool Fixed::operator<=(Fixed const &cpy) const {
    return (this->_num <= cpy.getRawBits());
}

bool Fixed::operator!=(Fixed const &cpy) const {
    return (this->_num != cpy.getRawBits());
}
/**
 * Overloaded arithmetic operators
*/
Fixed   Fixed::operator+(const Fixed &cpy) const {
    return (Fixed(this->toFloat() + cpy.toFloat()));
}

Fixed   Fixed::operator-(const Fixed &cpy) const {
    return (Fixed(this->toFloat() - cpy.toFloat()));
}

Fixed   Fixed::operator*(const Fixed &cpy) const {
    return (Fixed(this->toFloat() * cpy.toFloat()));
}

Fixed   Fixed::operator/(const Fixed &cpy) const {
    if (cpy.getRawBits() == 0)
    {
        std::runtime_error("Dividing by zero");
        exit(1);
    }
    return (Fixed(this->toFloat() / cpy.toFloat()));
}
/**
 * Increment and Decrement
*/
Fixed&  Fixed::operator++(void) {
    this->_num++;
    return *this;
}

Fixed&  Fixed::operator--(void) {
    this->_num--;
    return *this;
}

Fixed   Fixed::operator++(int) {
    Fixed tmp = *this;
    ++this->_num;
    return tmp;
}

Fixed   Fixed::operator--(int) {
    Fixed tmp(*this);
    --this->_num;
    return tmp;
}
/**
 * Public overloaded member function
*/   
Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b ? a : b);
}
