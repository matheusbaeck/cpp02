/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:45 by math              #+#    #+#             */
/*   Updated: 2024/07/01 21:42:27 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iomanip>
# include <sstream> //stream strig

std::string printBit(int nb)
{
	std::string			str = "(";
	std::stringstream	ss;

	for (size_t i = 0; i < 32; i++)
	{
		if (i != 0 && i % 8 == 0)
			ss << " ";
		ss << ((nb >> (31 - i)) & 1);
	}
	str += ss.str() + ")";
	return str;
}

std::string	printBitRaw(float f)
{
	int	num;

	std::memcpy(&num, &f, sizeof(f));
	return (printBit(num));
}

std::string printBit(float f)
{
	int	num;

	std::memcpy(&num, &f, sizeof(f));

	// Extract the exponent part (bits 23 to 30)
	int exponent = (num >> 23) & 0xFF;
	int adjusted_exponent = exponent - 127;

	std::string str = "(";
	std::stringstream ss;

	// Sign bit
	ss << ((num >> 31) & 1) << " ";

	// Format exponent part into a temporary string
	std::stringstream exponent_ss;
	exponent_ss << exponent << "(" << adjusted_exponent << ")";

	// Ensure the whole exponent part fits in 8 spaces
	ss << std::setw(8) << std::left << exponent_ss.str();

	// Mantissa
	for (size_t i = 9; i < 32; i++)
	{
		if (i != 0 && i % 8 == 0)
			ss << " ";
		ss << ((num >> (31 - i)) & 1);
	}

	str += ss.str() + ")";
	return str;
}

#include "limits.h"
int main( void )
{
	Fixed 		a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
