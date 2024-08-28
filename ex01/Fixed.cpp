#include "Fixed.hpp"

const int Fixed::fract_bits = 8;


Fixed::Fixed(): value(0)
{
    std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int input)
{
    std::cout << "Int Constructor called" << std::endl;
    this->value = input << this->fract_bits;
}

Fixed::Fixed(const float input)
{
    std::cout << "Float Constructor called" << std::endl;
    this->value = roundf(input * (1 << this->fract_bits));
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


float	Fixed::toFloat(void)const
{
    return ((float)this->value / (float)(1 << this->fract_bits));
}

int	Fixed::toInt(void)const
{
    return (this->value >> this->fract_bits);
}

int	Fixed::getRawBits(void)const
{
    return (this->value);
}


void	Fixed::setRawBits(int const raw)
{
    this->value = raw;
}


std::ostream	&operator<<(std::ostream &o, Fixed const &fixed)
{
    o << fixed.toFloat();
    return (o);
}