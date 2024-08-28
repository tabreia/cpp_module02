#include "Fixed.hpp"


const int Fixed::fract_bits = 8;

Fixed::Fixed(): value(0)
{
}

Fixed::Fixed(const int input)
{
    this->value = input << this->fract_bits;
}

Fixed::Fixed(const float input)
{
    this->value = roundf(input * (1 << this->fract_bits));
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
}

Fixed::~Fixed()
{
}

Fixed	&Fixed::operator=(const Fixed &src)
{
    if (this != &src)
        this->value = src.getRawBits();

    return *this;
}

bool	Fixed::operator>(Fixed fixed) const
{
    return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(Fixed fixed) const
{
    return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed) const
{
    return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed) const
{
    return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed) const
{
    return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed) const
{
    return (this->toFloat() != fixed.toFloat());
}

float	Fixed::operator+(Fixed fixed) const
{
    return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed fixed) const
{
    return (this->toFloat() - fixed.toFloat());
}

float	Fixed::operator*(Fixed fixed) const
{
    return (this->toFloat() * fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed) const
{
    return (this->toFloat() / fixed.toFloat());
}

Fixed	Fixed::operator++()
{
    this->value++;
    return (*this);
}

Fixed	Fixed::operator--()
{
    this->value--;
    return (*this);
}

Fixed	Fixed::operator++(int)
{
    Fixed tmp = *this;
    ++this->value;
    return (tmp);
}

Fixed	Fixed::operator--(int)
{
    Fixed tmp = *this;
    --this->value;
    return (tmp);
}

float	Fixed::toFloat(void)const
{
    return ((float)this->value / (float)(1 << this->fract_bits));
}

int	Fixed::toInt(void)const
{
    return (this->value >> this->fract_bits);
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
    if (first.toFloat() <= second.toFloat())
        return (first);
    else
        return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
    if (first.toFloat() <= second.toFloat())
        return (first);
    else
        return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
    if (first.toFloat() >= second.toFloat())
        return (first);
    else
        return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
    if (first.toFloat() >= second.toFloat())
        return (first);
    else
        return (second);
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