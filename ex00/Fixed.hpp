#pragma once

/*
	-The copy constructor creates a new instance of an object,
	and initializes it with the values of the object passed
	to it as a parameter.

	-The copy assignment operator overwrites an existing object's values
	with the values of another object passed to it as a parameter.
*/

class Fixed
{
private:
	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

public:
	Fixed(); //default constructor
	Fixed(const Fixed &source); //copy constructor
	Fixed &operator=(const Fixed &source); //copy assignment operator
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};