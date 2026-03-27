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

	//increments
	Fixed &operator++(void); //pre-increment
	Fixed operator++(int); //post-increment with dummy parameter
	Fixed &operator--(void); //pre-decrement
	Fixed operator--(int); //post-decrement with dummy parameter

	/*
		min/max functions
		Static here means that the functions are tied to the class
		blueprint, not a specific object. They are called like this:
		Fixed:max(a, b) NOT like a.max(a, b)
	*/
	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &source);