/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:30 by math              #+#    #+#             */
/*   Updated: 2024/06/04 19:48:25 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional_bits;

Fixed::Fixed( int value ) : _value(value >= 0 ? (value << 8) & ~(1 << 31) : value << 8 | (1 << 31)) // value >= 0 ? value << 8 : value << 8 | ((1 << 8) - 1)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float value)
{
	int	integer_part;
	int	fractional_part;

	//value = round_bits(value, Fixed::fractional_bits);
	integer_part = static_cast<int>(value);
	if ((value >= 0 ? integer_part : ~integer_part) & ~((1 << (32 - (Fixed::fractional_bits + 1))) - 1))
		std::cout << "integer part overflow" << std::endl;
	fractional_part = static_cast<int>((value - integer_part) * (1 << this->fractional_bits) * (value >= 0 ? 1 : -1));
	// printBit(fractional_part);
	// printBit(~(((1) << 8) - 1));
	// printBit(value);
	// printBit(fractional_part);
	// while (fractional_part & ~(((1) << 8) - 1))
	// {
	// 	std::cout << "while" << std::endl;
	// 	value = roundf(value);
	// 	printBit(value);
	// 	fractional_part = static_cast<int>((value - integer_part) * (1 << this->fractional_bits) * (value >= 0 ? 1 : -1));
	// }

	// still missing overflow protection and aproximation handle to fractional part
	this->_value = integer_part << Fixed::fractional_bits;
	// printBit(this->getRawBits());
	this->_value = (value >= 0) ? (this->_value & ~(1 << 31)) : (this->_value | (1 << 31));
	// printBit(this->getRawBits());

	this->_value |= fractional_part;
	// printBit(this->getRawBits());
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( void ) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
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

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
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

	std::memcpy(&f_fractional, &aux, sizeof(int));
	return (f_integer + (f_fractional - 1));
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
