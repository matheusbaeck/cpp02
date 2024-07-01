/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:30 by math              #+#    #+#             */
/*   Updated: 2024/07/01 12:24:23 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional_bits;

Fixed::Fixed( void ) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int value ) : _value(value >= 0 ? (value << 8) & ~(1 << 31) : value << 8 | (1 << 31))
{
	std::cout << "Int constructor called" << std::endl;
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
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
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
	return ((this->_value >> 8) | sign);
}

std::ostream	&operator<<(std::ostream &os, Fixed const &obj)
{
	os << obj.toFloat();
	return (os);
}

Fixed &Fixed::operator=(Fixed const &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
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

Fixed	&Fixed::operator/(Fixed const &obj)
{
	*this = Fixed(this->toFloat() / obj.toFloat());
	return (*this);
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
