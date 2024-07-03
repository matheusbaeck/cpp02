/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:30 by math              #+#    #+#             */
/*   Updated: 2024/07/03 12:43:58 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional_bits;

Fixed::Fixed( void ) : _value(0)
{
	std::cout << "Fixed Default constructor" << std::endl;
}

Fixed::Fixed( Fixed const &src)
{
	std::cout << "Fixed Copy constructor" << std::endl;
	*this = src;
}

Fixed::~Fixed( void )
{
	std::cout << "Fixed Destructor" << std::endl;
	return ;
}

Fixed &Fixed::operator=(Fixed const &obj)
{
	std::cout << "Fixed Copy assignment operator" << std::endl;
	this->_value = obj._value;
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits( int newValue )
{
	_value = newValue;
}
