#pragma once

#include <iostream>

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
	Fixed(int const val);
	Fixed(float const val);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const; //must be const to work with const objects
	int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &source);