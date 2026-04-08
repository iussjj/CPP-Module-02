#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;

}

Fixed::Fixed(const Fixed &source)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

Fixed& Fixed::operator=(const Fixed &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->_fixedPointValue = source.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
/*
	CONSTRUCTOR OVERLOADING:
	Multiple functions may have the same name, as long as they have
	different parameters. The correct one will be selected depending
	on the arguments given.
*/

Fixed::Fixed(int const val)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = val << this->_fractionalBits;
	/*
		int to fixed: bit-shift the int 8 to the left
		to make space for 8 decimal places
	*/
}

Fixed::Fixed(float const val)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(val * (1 << this->_fractionalBits));
	/*
		float to fixed: float * 256 (same as 1 << 8), rounded to
		the nearest whole number with roundf()
	*/
}

int Fixed::getRawBits(void) const //const = object member variables unchanged
{
	//std::cout << "getRawBits member function called" << std::endl;
	//not necessary for output matching subject
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

/*
	!THIS IS NOT THE WAY: (float)this->_fixedPointValue
	The C++ Way (🇩🇰): static_cast<float>(this->_fixedPointValue)
*/

float	Fixed::toFloat(void) const
{
	return static_cast<float>(this->_fixedPointValue)
		/ static_cast<float>(1 << this->_fractionalBits);
}

int		Fixed::toInt(void) const
{
	return this->_fixedPointValue >> this->_fractionalBits;
}

std::ostream& operator<<(std::ostream &out, const Fixed &source)
{
	out << source.toFloat(); //send return of toFloat to output stream
	return out; //return output stream
}

