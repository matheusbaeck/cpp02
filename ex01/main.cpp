/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:45 by math              #+#    #+#             */
/*   Updated: 2024/06/04 19:49:30 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void	printBit(int nb)
{
	std::cout  << "(";
	for (size_t i = 0; i < 32; i++)
	{
		if (i != 0 && i % 8 == 0)
			std::cout << " ";
		std::cout << ((nb >> (31 - i)) & 1);
	}
	std::cout << ")" << std::endl;
}

void printBit(float f)
{
	int num;
	std::memcpy(&num, &f, sizeof(f));
	printBit(num);
}

#include "limits.h"
int main( void )
{
	//float	fl = 23.1234f;
	float	fl = -17.1;
	Fixed	fi(fl);

	std::cout << fi << std::endl;
	// printBit(INT_MAX);
	// printBit(-1);
	// printBit(-2);
	// printBit(~(10 - 1));
	// printBit((-10));
	// printBit((10));
	// printBit(INT_MIN + 1);
	// printBit(INT_MIN | INT_MAX);
	// for (int i = INT_MIN; i >= -100; i++)
	// {
	// 	printBit(i);
	// }
	return 0;
	Fixed a;
	Fixed const b( -10 );
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
