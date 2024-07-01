/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:45 by math              #+#    #+#             */
/*   Updated: 2024/07/01 18:55:40 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Triangle.hpp"

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

int main( void )
{
	Triangle	abc(Point(0,0), Point(42,0), Point(0,42));
	Point		p(41.999999,0);

	std::cout << abc.getArea() << std::endl;
	std::cout << abc.cointain(p) << std::endl;
	// std::cout << "hey" << p << "bye" << std::endl;
	// std::cout << "hey" << abc << "bye" << std::endl;
}
