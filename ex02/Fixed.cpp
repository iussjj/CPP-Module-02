#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	//std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;

}

Fixed::Fixed(const Fixed &source)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

Fixed& Fixed::operator=(const Fixed &source)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->_fixedPointValue = source.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}
/*
	CONSTRUCTOR OVERLOADING:
	Multiple functions may have the same name, as long as they have
	different parameters. The correct one will be selected depending
	on the arguments given.
*/

Fixed::Fixed(int const val)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = val << this->_fractionalBits;
	/*
		int to fixed: bit-shift the int 8 to the left
		to make space for 8 decimal places
	*/
}

Fixed::Fixed(float const val)
{
	//std::cout << "Float constructor called" << std::endl;
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

bool	Fixed::operator>(const Fixed &right) const
{
	return this->_fixedPointValue > right.getRawBits();
}

bool	Fixed::operator<(const Fixed &right) const
{
	return this->_fixedPointValue < right.getRawBits();
}

bool	Fixed::operator>=(const Fixed &right) const
{
	return this->_fixedPointValue >= right.getRawBits();
}

bool	Fixed::operator<=(const Fixed &right) const
{
	return this->_fixedPointValue <= right.getRawBits();
}

bool	Fixed::operator==(const Fixed &right) const
{
	return this->_fixedPointValue == right.getRawBits();
}

bool	Fixed::operator!=(const Fixed &right) const
{
	return this->_fixedPointValue != right.getRawBits();
}

/*
	In C++, private variables are locked at the Class Level,
	not the Object Level, which is why right._fixedPointValue works!
*/

Fixed	Fixed::operator+(const Fixed &right) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointValue + right._fixedPointValue);
	return result;
}

Fixed	Fixed::operator-(const Fixed &right) const
{
	Fixed result;
	result.setRawBits(this->_fixedPointValue - right._fixedPointValue);
	return result;
}

Fixed	Fixed::operator*(const Fixed &right) const
{
	return Fixed(this->toFloat() * right.toFloat());
}

Fixed	Fixed::operator/(const Fixed &right) const
{
	return Fixed(this->toFloat() / right.toFloat());
}

/*
	Pre-increment operator: increments original object, then returns it
*/
Fixed&	Fixed::operator++(void)
{
	this->_fixedPointValue++;
	return *this;
}

/*
	Post-increment operator: returns non-incremented value
	Dummy parameter differentiates between pre and post increment operator.
	Because it is unnamed, it avoids the unused parameter compiler error.
*/
Fixed	Fixed::operator++(int)
{
	Fixed temp(*this); //copy constructor call to save pre-increment state
	this->_fixedPointValue++; //increment original object
	return temp; //return copied previous state by value
}

//	Pre-decrement operator: decrements original object, then returns it
Fixed&	Fixed::operator--(void)
{
	this->_fixedPointValue--;
	return *this;
}

/*
	Post-decrement operator: return non-decremented value
	Dummy parameter differentiates between pre and post decrement operator.
	Because it is unnamed, it avoids the unused parameter compiler error.
*/

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_fixedPointValue--;
	return temp;
}

/*
	Min and max functions use the overloaded < and > operators
	to compare the values of fixed objects a and b, so the code
	here is simple.

	NOTES:
	-No static keyword in function implementation
	-Scope resolution Fixed:: still needed, since these aren't
	stand-alone functions but belong to the Fixed class blueprint

*/

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

 Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

 const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

