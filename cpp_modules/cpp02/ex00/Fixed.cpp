#include "Fixed.hpp"

Fixed::Fixed(void) : _num(0)
{
    std::cout << "Default constructor called" << std::endl;
}


Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}
Fixed::Fixed(Fixed const &cpy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = cpy;
    return;
}

Fixed & Fixed::operator=(Fixed const & val) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &val)
        this->_num = val.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_num);
}

void Fixed::setRawBits(int const raw) {
    this->_num = raw;
}
