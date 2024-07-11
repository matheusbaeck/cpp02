/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:30 by math              #+#    #+#             */
/*   Updated: 2024/07/05 18:10:25 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional_bits;

Fixed::Fixed( void ) : _value(0)
{
	std::cout << "Fixed Default constructor" << std::endl;
}

Fixed::Fixed( int value ) : _value(value >= 0 ? (value << this->fractional_bits) & ~(1 << 31) : value << this->fractional_bits | (1 << 31))
{
	std::cout << "Fixed Int constructor" << std::endl;
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
	std::cout << "Fixed Float constructor" << std::endl;
}

Fixed::Fixed( Fixed const &src)
{
	std::cout << "Fixed Copy constructor " << std::endl;
	*this = src;
}

Fixed::~Fixed( void )
{
	std::cout << "Fixed Destructor" << std::endl;
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
	int		mantissa = (this->_value & ((1 << this->fractional_bits) - 1)) << (23 - this->fractional_bits);
	int		aux = ((127 << 23) | mantissa);

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
	if (!(this->_value & (~(1 << 31) - ((1 << this->fractional_bits) - 1))) && (this->_value & ((1 << this->fractional_bits) - 1)))
		return (-0);
	return (((this->_value) >> this->fractional_bits));
}

std::ostream	&operator<<(std::ostream &os, Fixed const &obj)
{
	if (!(obj.getRawBits() & ((1 << Fixed::fractional_bits) - 1)))
		os << obj.toInt();
	else
		os << obj.toFloat();
	return (os);
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Fixed Copy assignment operator" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}
