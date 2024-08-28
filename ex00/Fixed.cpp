#include "Fixed.hpp"

const int Fixed::fract_bits = 8;

Fixed::Fixed(): value(0)
{
    std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy Constructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed()
{
    std::cout << "Deconstructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &src)
        this->value = src.getRawBits();

    return *this;
}

int	Fixed::getRawBits(void)const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}