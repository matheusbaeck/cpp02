/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:30 by math              #+#    #+#             */
/*   Updated: 2024/07/03 12:51:40 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional_bits;

Fixed::Fixed( void ) : _value(0)
{
	// std::cout << "Fixed Default constructor" << std::endl;
}

Fixed::Fixed( int value ) : _value(value >= 0 ? (value << this->fractional_bits) & ~(1 << 31) : value << this->fractional_bits | (1 << 31))
{
	// std::cout << "Fixed Int constructor" << std::endl;
}

Fixed::Fixed(float value)
{
	int	integer_part;
	int	fractional_part;

	integer_part = static_cast<int>(value);
	fractional_part = static_cast<int>((value - integer_part) * (1 << this->fractional_bits) * (value >= 0 ? 1 : -1));
	this->_value = integer_part << Fixed::fractional_bits;
	this->_value = (value >= 0) ? (this->_value & ~(1 << 31)) : (this->_value | (1 << 31));
	this->_value |= fractional_part;
	// std::cout << "Fixed Float constructor" << std::endl;
}

Fixed::Fixed( Fixed const &src)
{
	// std::cout << "Fixed Copy constructor" << std::endl;
	*this = src;
}

Fixed::~Fixed( void )
{
	// std::cout << "Fixed Destructor " << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	return (this->_value);
}

void	Fixed::setRawBits( int newValue )
{
	_value = newValue;
}

float	Fixed::toFloat( void ) const
{
	float	f_integer = static_cast<float>(this->toInt());
	float	f_fractional = 0;
	int		expo = 127 << 23;
	int		mantissa = (this->_value & ((1 << 8) - 1)) << (23 - 8);
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
	int	sign_mask = (1 << 31);
	int	sign;

	sign = this->_value & sign_mask;
	return ((this->_value >> this->fractional_bits) | sign);
}

std::ostream	&operator<<(std::ostream &os, Fixed const &obj)
{
	os << obj.toFloat();
	return (os);
}

Fixed &Fixed::operator=(Fixed const &obj)
{
	// std::cout << "Copy assignment operator " << std::endl;
	this->_value = obj.getRawBits();
	return (*this);
}

Fixed	&Fixed::operator+(Fixed const &obj)
{
	*this = Fixed(this->toFloat() + obj.toFloat());
	return (*this);
}

Fixed	&Fixed::operator-(Fixed const &obj)
{
	*this = Fixed(this->toFloat() - obj.toFloat());
	return (*this);
}

Fixed	&Fixed::operator*(Fixed const &obj)
{
	*this = Fixed(this->toFloat() * obj.toFloat());
	return (*this);
}

Fixed	&Fixed::operator*(float const &obj)
{
	*this = Fixed(this->toFloat() * obj);
	return (*this);
}

Fixed	&Fixed::operator/(Fixed const &obj)
{
	*this = Fixed(this->toFloat() / obj.toFloat());
	return (*this);
}

Fixed	&Fixed::operator/(float const &obj)
{
	*this = Fixed(this->toFloat() / obj);
	return (*this);
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
	int	frac_mask = (1<< this->fractional_bits) - 1;
	int	sign_mask = 1 << 31;
	int	int_mask = (sign_mask - 1) - frac_mask;

	if ((this->_value & sign_mask & int_mask) > (obj._value & sign_mask & int_mask))
		return (true);
	else if ((this->_value & sign_mask & int_mask) < (obj._value & sign_mask & int_mask))
		return (false);
	else
		return (this->_value & sign_mask & frac_mask) > (obj._value & sign_mask & frac_mask);
}

bool	Fixed::operator<(Fixed const &obj) const
{
	int	frac_mask = (1<< this->fractional_bits) - 1;
	int	sign_mask = 1 << 31;
	int	int_mask = (frac_mask - 1) - frac_mask;

	if ((this->_value & sign_mask & int_mask) < (obj._value & sign_mask & int_mask))
		return (true);
	else if ((this->_value & sign_mask & int_mask) > (obj._value & sign_mask & int_mask))
		return (false);
	else
		return (this->_value & sign_mask & frac_mask) < (obj._value & sign_mask & frac_mask);
}

bool	Fixed::operator>=(Fixed const &obj) const
{
	return (this->_value == obj._value || this->_value > obj._value);
}

bool	Fixed::operator<=(Fixed const &obj) const
{
	return (this->_value == obj._value || this->_value < obj._value);
}

bool	Fixed::operator!=(Fixed const &obj) const
{
	return (!(*this == obj));
}
