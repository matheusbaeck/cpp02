/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:45 by math              #+#    #+#             */
/*   Updated: 2024/07/01 12:02:19 by math             ###   ########.fr       */
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
	Fixed a(2.3f);
	Fixed b(1.5f);
	Fixed c;

	std::cout << "a is:" << a << " " << "float:" << a.toFloat() << " int:" << a.toInt() << std::endl;
	std::cout << "b is:" << b << " " << "float:" << b.toFloat() << " int:" << b.toInt() << std::endl;


	c = a + b;
	std::cout << "c = a + b" << std::endl;
	std::cout << "\tc is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

	c = a - b;
	std::cout << "c = a - b" << std::endl;
	std::cout << "\tc is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

	c = a * b;
	std::cout << "c = a * b" << std::endl;
	std::cout << "\tc is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

	c = a / b;
	std::cout << "c = a / b" << std::endl;
	std::cout << "\tc is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

	return 0;
}
