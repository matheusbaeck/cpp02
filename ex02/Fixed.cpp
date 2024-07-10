/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:30 by math              #+#    #+#             */
/*   Updated: 2024/07/10 14:14:27 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional_bits;

Fixed::Fixed( void ) : _value(0) {}

Fixed::Fixed( int value ) : _value(value >= 0 ? (value << this->fractional_bits) & ~(1 << 31) : value << this->fractional_bits | (1 << 31)) {}

/*
static int	shiftMantissa( int nb )
{
	int	sign = nb & (1 << 31);
	int mantissa = nb & ((1 << 23) - 1);
	int	exp = nb & (255 << 23);

	while ((exp >> 23) <= 127 && mantissa && (mantissa & (1 << 22)) & 0)
	{
		mantissa = (mantissa << 1) & ((1 << 23) - 1);
		exp += (1 << 23);
		nb = (sign | exp | mantissa);
	}
	return (nb);
}

Fixed::Fixed(float value)
{
	float	aux;
	int		sign;
	int		integer_part;
	int		fractional_part;

	sign = 0;
	if (value < 0)
		sign = (1 << 31);
	integer_part = static_cast<int>(value);
	integer_part = (integer_part << this->fractional_bits) & (~(1 << 31) - ((1 << this->fractional_bits) - 1));
	aux = shiftMantissa(value - integer_part);
	std::memcpy(&fractional_part, &aux, sizeof(float));
	fractional_part = (fractional_part & ((1 << 23) - 1)) >> (23 - this->fractional_bits);
	this->_value = (sign | integer_part | fractional_part);
}*/

Fixed::Fixed(float value)
{
	int	integer_part;
	int	fractional_part;

	integer_part = static_cast<int>(value);
	fractional_part = static_cast<int>((value - integer_part) * (1 << this->fractional_bits) * (value >= 0 ? 1 : -1));
	this->_value = integer_part << Fixed::fractional_bits;
	this->_value = (value >= 0) ? (this->_value & ~(1 << 31)) : (this->_value | (1 << 31));
	this->_value |= fractional_part;
}


Fixed::Fixed( Fixed const &src) { *this = src; }

Fixed::~Fixed( void ) {}

int	Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void	Fixed::setRawBits( int newValue )
{
	this->_value = newValue;
}

float	Fixed::toFloat( void ) const
{
	float	f_integer = static_cast<float>(this->toInt());
	float	f_fractional = 0;
	int		expo = 127 << 23;
	int		mantissa = (this->_value & ((1 << this->fractional_bits) - 1)) << (23 - this->fractional_bits);
	int		aux = (expo | mantissa);

	if (mantissa == 0)
		return(f_integer);
	std::memcpy(&f_fractional, &aux, sizeof(int));
	if (this->_value & (1 << 31))
	{
		f_fractional *= (-1.f);
		f_fractional += 1;
	}
	else
		f_fractional -= 1;
	return (f_integer + f_fractional);
}

int		Fixed::toInt( void ) const
{
	// int	sign_mask = (1 << 31);
	// int	int_mask = sign_mask - (1 << this->fractional_bits);

	// if (this->_value & sign_mask)
	// {
	// 	return (((this->_value) >> this->fractional_bits));
	// }
	return (((this->_value) >> this->fractional_bits));
}

std::ostream	&operator<<(std::ostream &os, Fixed const &obj)
{
	if (obj.getRawBits() & ((1 << Fixed::fractional_bits) - 1))
		os << obj.toInt();
	else
		os << obj.toFloat();
	return (os);
}

Fixed &Fixed::operator=(Fixed const &obj)
{
	this->_value = obj.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &obj) const
{
	return (Fixed(this->toFloat() + obj.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &obj) const
{
	return (Fixed(this->toFloat() - obj.toFloat()));
}

Fixed	Fixed::operator*(Fixed const &obj) const
{
	return (Fixed(this->toFloat() * obj.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &obj) const
{
	return (Fixed(this->toFloat() / obj.toFloat()));
}

Fixed	&Fixed::operator++()
{
	this->_value = this->_value + (1 << this->fractional_bits);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	this->_value = this->_value + (1 << this->fractional_bits);
	return (temp);
}

Fixed	&Fixed::operator--()
{
	this->_value = this->_value - (1 << this->fractional_bits);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	this->_value = this->_value - (1 << this->fractional_bits);
	return (temp);
}


bool	Fixed::operator==(Fixed const &obj) const
{
	for (int i = 0; i < 32; i++)
	{
		if ((this->_value << i) != (obj._value << i))
			return (false);
	}
	return (true);
}

bool	Fixed::operator>(Fixed const &obj) const
{
	if ((this->_value & (1 << 31)) != (obj._value & (1 << 31)))
		return (!(this->_value & (1 << 31)));
	for (int i = 30; i >= 0; i--)
	{
		if ((this->_value & (1 << i)) != (obj._value & (1 << i)))
			return (this->_value & (1 << i));
	}
	return (false);
	// return (this->_value > obj._value);
}

bool	Fixed::operator<(Fixed const &obj) const
{
	if ((this->_value & (1 << 31)) != (obj._value & (1 << 31)))
		return (this->_value & (1 << 31));
	for (int i = 30; i >= 0; i--)
	{
		if ((this->_value & (1 << i)) != (obj._value & (1 << i)))
			return (!(this->_value & (1 << i)));
	}
	return (false);
	// return (this->_value < obj._value);
}

bool	Fixed::operator>=(Fixed const &obj) const
{
	if ((this->_value & (1 << 31)) != (obj._value & (1 << 31)))
		return (!(this->_value & (1 << 31)));
	for (int i = 30; i >= 0; i--)
	{
		if ((this->_value & (1 << i)) != (obj._value & (1 << i)))
			return (this->_value & (1 << i));
	}
	return (true);
	// return (this->_value >= obj._value);
}

bool	Fixed::operator<=(Fixed const &obj) const
{
	if ((this->_value & (1 << 31)) != (obj._value & (1 << 31)))
		return (this->_value & (1 << 31));
	for (int i = 30; i >= 0; i--)
	{
		if ((this->_value & (1 << i)) != (obj._value & (1 << i)))
			return (!(this->_value & (1 << i)));
	}
	return (true);
	// return (this->_value <= obj._value);
}

bool	Fixed::operator!=(Fixed const &obj) const
{
	return (!(*this == obj));
}

Fixed	&Fixed::min(Fixed& a, Fixed& b)
{
	return ((a <= b) ? a : b);
}

Fixed const &Fixed::min(const Fixed& a, const Fixed& b)
{
	return ((a <= b) ? a : b);
}

Fixed	&Fixed::max(Fixed& a, Fixed& b)
{
	return ((a >= b) ? a : b);
}

Fixed const &Fixed::max(const Fixed& a, const Fixed& b)
{
	return ((a >= b) ? a : b);
}
