#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int	value;
    static const int fract_bits;

public:
    Fixed();
    Fixed(const int input);
    Fixed(const float input);
    Fixed(const Fixed& copy);

    ~Fixed();

    Fixed &operator=(const Fixed &src);

    float toFloat(void)const;
    int toInt(void)const;
    int getRawBits(void)const;
    void setRawBits(int const raw);
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);