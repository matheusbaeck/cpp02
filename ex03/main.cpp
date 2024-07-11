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
#include <sstream> //stream strig
#include <cstdlib>

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

int main( int argc, char **argv )
{
	Triangle abc;
	Point    p;

	if (argc == 9)
	{
		abc = Triangle(Point(atof(argv[1]),atof(argv[2])), Point(atof(argv[3]),atof(argv[4])), Point(atof(argv[5]),atof(argv[6])));
		p = Point(atof(argv[7]),atof(argv[8]));
	}
	else if (argc == 7)
	{
		abc = Triangle(Point(atof(argv[1]),atof(argv[2])), Point(atof(argv[3]),atof(argv[4])), Point(atof(argv[5]),atof(argv[6])));
		p = Point(42,42);
	}
	else if (argc == 3)
	{
		abc = Triangle(Point(0,0), Point(42,0), Point(0,42));
		p = Point(atof(argv[1]),atof(argv[2]));
	}
	else
	{
		abc = Triangle(Point(0,0), Point(42,0), Point(0,42));
		p = Point(41.9, 77);
	}
	std::cout << "Does triangle " << abc << " contain point " << p << "?" << std::endl;
	std::cout << "Triangle total area is:" << abc.getArea() << std::endl;
	std::cout << (abc.cointain(p) ? "True" : "False") << std::endl;
	return (0);
}
