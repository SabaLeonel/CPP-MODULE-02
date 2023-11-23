#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0)
{
    return ;
}

Fixed::Fixed(const Fixed &other)
{

    *this = other;
}

Fixed::Fixed(const int value)
{
    this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
    this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

Fixed::~Fixed(void)
{
    return ;
}

float Fixed::toFloat(void) const
{
    return (float)this->_fixedPointValue / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->_fixedPointValue >> this->_fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

int Fixed::operator>(const Fixed &other) const
{
    return this->_fixedPointValue > other.getRawBits();
}

int Fixed::operator<(const Fixed &other) const
{
    return this->_fixedPointValue < other.getRawBits();
}

int Fixed::operator>=(const Fixed &other) const
{
    return this->_fixedPointValue >= other.getRawBits();
}

int Fixed::operator<=(const Fixed &other) const
{
    return this->_fixedPointValue <= other.getRawBits();
}

int Fixed::operator==(const Fixed &other) const
{
    return this->_fixedPointValue == other.getRawBits();
}

int Fixed::operator!=(const Fixed &other) const
{
    return this->_fixedPointValue != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++(void)
{
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--(void)
{
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return a > b ? a : b;
}


