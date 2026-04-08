#pragma once

/*
	-The copy constructor creates a new instance of an object,
	and initializes it with the values of the object passed
	to it as a parameter.

	-The copy assignment operator overwrites an existing object's values
	with the values of another object passed to it as a parameter.

	NOTE: static const int	_fractionalBits = 8;
	static = variable is shared across all objects of this class
	const = read only

	!MEMBER VARIABLES MAY ONLY BE INITIALIZED IN THE CLASS BLUEPRINT
	!WHEN THEY ARE 1. THEY ARE STATIC 2. THEY ARE CONST 3. THEY ARE INTEGRAL
	!TYPES LIKE INT, CHAR, BOOL (NOT FLOAT!)
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