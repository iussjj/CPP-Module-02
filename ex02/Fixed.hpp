#pragma once

#include <iostream>

class Fixed
{
private:
	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &source);
	Fixed &operator=(const Fixed &source);
	~Fixed();

	//overloaded constructors
	Fixed(int const val);
	Fixed(float const val);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	//comparison operators
	bool	operator>(const Fixed &right) const;
	bool	operator<(const Fixed &right) const;
	bool	operator>=(const Fixed &right) const;
	bool	operator<=(const Fixed &right) const;
	bool	operator==(const Fixed &right) const;
	bool	operator!=(const Fixed &right)const;

	//arithmetic operators
	Fixed operator+(const Fixed &right) const;
	Fixed operator-(const Fixed &right) const;
	Fixed operator*(const Fixed &right) const;
	Fixed operator/(const Fixed &right) const;

};

std::ostream &operator<<(std::ostream &out, const Fixed &source);