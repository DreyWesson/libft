#include "Fixed.hpp"

Fixed::Fixed(void) : _num(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const num) : _num(num * (1 << _fractional_bits)) {
    std::cout << "Int parameterized constructor called" << std::endl;
}

Fixed::Fixed(float const num) : _num(roundf(num * (1 << _fractional_bits))) {
    std::cout << "Float parameterized constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &cpy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = cpy;
    return ;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed & Fixed::operator=(Fixed const & val) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &val)
        this->_num = val.getRawBits();
    return *this;
}

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

std::ostream & operator<<(std::ostream &cout, Fixed const & i) {
    cout << i.toFloat();
    return (cout);
}