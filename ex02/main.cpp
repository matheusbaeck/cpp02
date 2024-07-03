/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:45 by math              #+#    #+#             */
/*   Updated: 2024/07/01 22:18:03 by math             ###   ########.fr       */
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
	Fixed a(2.25f);
	Fixed b(1.5f);
	Fixed c;

	std::cout << "a is:" << a << " " << "float:" << a.toFloat() << " int:" << a.toInt() << std::endl;
	std::cout << "b is:" << b << " " << "float:" << b.toFloat() << " int:" << b.toInt() << std::endl;

	/* SUM */
	c = a + b;
	std::cout << "c = a + b" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

	/* SUBS */
	c = a - b;
	std::cout << "c = a - b" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

	c = b - a;
	std::cout << "c = b - a" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

	c = b - ( a * (-1.0f));
	std::cout << "b - (-a))" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

	c = (b * (-1.0f)) - a;
	std::cout << "c = (-b) - a" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
	
	c = (b * (-1.0f)) - ( a * (-1.0f));
	std::cout << "(-b) - (-a))" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

	/* PROD */
	c = a * b;
	std::cout << "c = a * b" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

	c = b * ( a * (-1.0f));
	std::cout << "b * (-a))" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

	c = (b * (-1.0f)) * a;
	std::cout << "c = (-b) * a" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
	
	c = (b * (-1.0f)) * ( a * (-1.0f));
	std::cout << "(-b) * (-a))" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

	/* DIV */
	c = a * b;
	std::cout << "c = a / b" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

	c = b * ( a * (-1.0f));
	std::cout << "b / (-a))" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

	c = (b * (-1.0f)) / a;
	std::cout << "c = (-b) / a" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
	
	c = (b * (-1.0f)) / ( a * (-1.0f));
	std::cout << "(-b) / (-a))" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

	c = (b * (0.0f)) / ( a * (-1.0f));
	std::cout << "(b * 0) / (-a))" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

	c = (b) / ( a * 0.0f);
	std::cout << "b / (a * 0)" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

	/* INCREMENT/DECREMENT */
	c++;
	std::cout << "c++" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
	std::cout << "++c" << std::endl;
	std::cout << "c is:" << ++c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

	c--;
	std::cout << "c--" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
	std::cout << "--c" << std::endl;
	std::cout << "c is:" << --c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
	
	c--;
	std::cout << "c--" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
	c--;
	std::cout << "c--" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
	c--;
	std::cout << "c--" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
	c++;
	std::cout << "c++" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
	c++;
	std::cout << "c++" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
	c++;
	std::cout << "c++" << std::endl;
	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

	/* COMPARISON */
	std::cout << "a == b " << (a == b) << std::endl;
	std::cout << "a == a " << (a == a) << std::endl;
	std::cout << "a != b " << (a != b) << std::endl;
	std::cout << "a != a " << (a != a) << std::endl;
	std::cout << "a < b " << (a < b) << std::endl;
	std::cout << "a > b " << (a > b) << std::endl;
	std::cout << "a < (b * (-1.0f)) " << (a < (b * (-1.0f))) << std::endl;
	std::cout << "a > (b * (-1.0f)) " << (a > (b * (-1.0f))) << std::endl;
	std::cout << "(a * (-1.0f)) < (b * (-1.0f)) " << ((a * (-1.0f)) < (b * (-1.0f))) << std::endl;
	std::cout << "(a * (-1.0f)) > (b * (-1.0f)) " << ((a * (-1.0f)) > (b * (-1.0f))) << std::endl;
	std::cout << "a <= b " << (a <= b) << std::endl;
	std::cout << "a >= b " << (a >= b) << std::endl;
	std::cout << "a <= (b * (-1.0f)) " << (a <= (b * (-1.0f))) << std::endl;
	std::cout << "a >= (b * (-1.0f)) " << (a <= (b * (-1.0f))) << std::endl;


	return (0);
}
