#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;

}
/*
	*this = source; calls the copy assignment operator
	1. *this = go to memory address and open object it points to
	2. '=' = activate the operator= function
	3. pass source object to operator function for copying

*/


Fixed::Fixed(const Fixed &source)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}
/*
	The copy assignmment operator must be named and prototyped like this,
	so the compiler knows to call it when performing an operation like
	a = b (where a and b are Fixed objects)

	Required syntax: [Return Type] [Class Name]:: [Function Name]

	NOTE: in this syntax 'if (this != &source)' 'this' is a memory
	address (*this would be the object itself) while &source is the
	memory address of source, which itself is the object itself

	NOTE2 - THE TWO FACES OF '&'
	1. 	In a declaration/parameter list: (Fixed &source) '&' means "Reference".
		It creates an alias to an object so you don't have to copy it.
	2.	In front of an existing variable: (&source) It means "Address-Of".
		It extracts the memory address of that object.

*/
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

int Fixed::getRawBits(void) const //const = object member variables unchanged
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}
/*
	void Fixed::setRawBits(int const raw) 
	const = the value of raw (which is a local copy of the value passed)
	will remain unchanged even inside the scope of the function.
	Without it, local changes could be made, but nothing outside the
	function scope would be affected.
	NOTE: (int const raw) = (const int raw)
	(int const raw) preferable, since it reads r->l as raw is a constant int
*/

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}
