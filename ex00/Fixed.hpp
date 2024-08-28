#pragma once

#include <iostream>

class Fixed
{
    private:
        int	value;
        static const int fract_bits;

    public:
        Fixed();
        Fixed(const Fixed& copy);

        ~Fixed();

        Fixed &operator=(const Fixed &src);

        int getRawBits(void)const;
        void setRawBits(int const raw);

};