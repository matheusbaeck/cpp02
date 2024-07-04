/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:45 by math              #+#    #+#             */
/*   Updated: 2024/07/04 00:17:51 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>
#include "limits.h"

void	printBit(int nb)
{
	std::cout << "(";
	for (size_t i = 0; i < 32; i++)
	{
		if (i != 0 && i % 8 == 0)
			std::cout << " ";
		std::cout << ((nb >> (31 - i)) & 1);
	}
	std::cout << ")" << std::endl;
}

void	printBit(float f)
{
	int	num;

	std::memcpy(&num, &f, sizeof(f));
	printBit(num);
}

void	testLimits( void )
{
	std::cout << std::setw(12) << Fixed(INT_MAX) << std::setw(12) << Fixed(INT_MAX).toInt() << std::endl;
	/* printBit(Fixed(INT_MAX).getRawBits());
	printBit(Fixed(INT_MAX).toInt());
	printBit(Fixed(INT_MAX).toFloat()); */
	printBit(INT_MAX);
}

void	printTestResult(const std::string &operation, const Fixed &a, const Fixed &b, const Fixed &result, float expected)
{
	std::cout << a << " " << operation << " " << b << " = " << result << " (Expected: " << expected << ")-> " << (result.toFloat() == expected ? "OK" : "Error") << std::endl;
}

void	testAddition(float a, float b)
{
	Fixed	fa(a);
	Fixed	fb(b);

	printTestResult("+", fa, fb, fa + fb, a + b);
}

void	testSubtraction(float a, float b)
{
	Fixed	fa(a);
	Fixed	fb(b);

	printTestResult("-", fa, fb, fa - fb, a - b);
	printTestResult("-", fb, fa, fb - fa, b - a);
	printTestResult("-", fb, fa * -1.0f, fb - (fa * -1.0f), b - (a * -1.0f));
	printTestResult("-", fb * -1.0f, fa, (fb * -1.0f) - fa, (b * -1.0f) - a);
	printTestResult("-", fb * -1.0f, fa * -1.0f, (fb * -1.0f) - (fa * -1.0f), (b * -1.0f) - (a * -1.0f));
}

void	testMultiplication(float a, float b)
{
	Fixed	fa(a);
	Fixed	fb(b);

	printTestResult("*", a, b, fa * fb, a * b);
	printTestResult("*", b, a * -1.0f, fb * (fa * -1.0f), b * (a * -1.0f));
	printTestResult("*", b * -1.0f, a, (fb * -1.0f) * fa, (b * -1.0f) * a);
	printTestResult("*", b * -1.0f, a * -1.0f, (fb * -1.0f) * (fa * -1.0f), (b * -1.0f) * (a * -1.0f));
}

void	testDivision(float a, float b)
{

	Fixed	fa(a);
	Fixed	fb(b);

	printTestResult("/", fa, fb, fa / fb, a / b);
	printTestResult("/", fb, fa * -1.0f, fb / (fa * -1.0f), b / (a * -1.0f));
	printTestResult("/", fb * -1.0f, fa, (fb * -1.0f) / fa, (b * -1.0f) / a);
	printTestResult("/", fb * -1.0f, fa * -1.0f, (fb * -1.0f) / (fa * -1.0f), (b * -1.0f) / (a * -1.0f));
	printTestResult("/", fb * 0.0f, fa * -1.0f, (fb * 0.0f) / (fa * -1.0f), (b * 0.0f) / (a * -1.0f));
	try
	{
		std::cout << "b / (a * 0) = " << b / (a * 0.0f) << "-> Error (Division by zero not handled)" << std::endl;
	}
	catch (...)
	{
		std::cout << "b / (a * 0)-> OK (Division by zero handled)" << std::endl;
	}
}

void	testIncrementDecrement(void)
{
	float	f = -2.5f;
	Fixed	c(f);

	std::cout << "Initial c: " << c << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "++c:" << std::setw(10) << ++c << ":" << std::setw(10) << c << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "--c:" << std::setw(10) << --c << ":" << std::setw(10) << c << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "c++:" << std::setw(10) << c++ << ":" << std::setw(10) << c << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "c--:" << std::setw(10) << c-- << ":" << std::setw(10) << c << std::endl;
}

void	testComparison(float a, float b)
{
	Fixed	fa(a);
	Fixed	fb(b);

	std::cout << fa << " == " << fb << " :" << (fa == fb) << "-> " << ((fa == fb) == (a == b) ? "OK" : "Error") << std::endl;
	std::cout << fa << " == " << fa << " :" << (fa == fa) << "-> " << ((fa == fa) == (a == a) ? "OK" : "Error") << std::endl;
	std::cout << fa << " != " << fb << " :" << (fa != fb) << "-> " << ((fa != fb) == (a != b) ? "OK" : "Error") << std::endl;
	std::cout << fa << " != " << fa << " :" << (fa != fa) << "-> " << ((fa != fa) == (a != a) ? "OK" : "Error") << std::endl;
	std::cout << fa << " > " << fb << " :" << (fa > fb) << "-> " << ((fa > fb) == (a > b) ? "OK" : "Error") << std::endl;
	std::cout << fa << " > " << (fb * -1.0f) << " :" << (fa > (fb * -1.0f)) << " -> " << ((fa > (fb *-1.0f)) == (a > (b *-1.0f)) ? "OK" : "Error") << std::endl;
	std::cout << (fa * -1.0f) << " > " << fb << " :" << ((fa * -1.0f) > fb) << " -> " << (((fa * -1.0f) > fb) == ((a *-1.0f) > b) ? "OK" : "Error") << std::endl;
	std::cout << (fa * -1.0f) << " > " << (fb * -1.0f) << " :" << ((fa * -1.0f) > (fb *-1.0f)) << " -> " << (((fa * -1.0f) > (fb *-1.0f)) == ((a * -1.0f) > (b *-1.0f)) ? "OK" : "Error") << std::endl;
	std::cout << fa << " < " << fb << " :" << (fa < fb) << "-> " << ((fa < fb) == (a < b) ? "OK" : "Error") << std::endl;
	std::cout << fa << " < " << (fb * -1.0f) << " :" << (fa < (fb * -1.0f)) << " -> " << ((fa < (fb *-1.0f)) == (a < (b *-1.0f)) ? "OK" : "Error") << std::endl;
	std::cout << (fa * -1.0f) << " < " << (fb * -1.0f) << " :" << ((fa * -1.0f) < (fb *-1.0f)) << " -> " << (((fa * -1.0f) < (fb *-1.0f)) == ((a * -1.0f) < (b *-1.0f)) ? "OK" : "Error") << std::endl;
	std::cout << fa << " >= " << fb << " :" << "-> " << ((fa >= fb) == (a >= b) ? "OK" : "Error") << std::endl;
	std::cout << fa << " >= " << (fb * -1.0f) << " :" << "-> " << ((fa >= (fb * -1.0f)) == (a >= (b * -1.0f)) ? "OK" : "Error") << std::endl;
	std::cout << fa << " <= " << fb << " :" << "-> " << ((fa <= fb) == (a <= b) ? "OK" : "Error") << std::endl;
	std::cout << fa << " <= " << (fb * -1.0f) << " :" << "-> " << ((fa <= (fb * -1.0f)) == (a <= (b * -1.0f)) ? "OK" : "Error") << std::endl;
}

void	testMaxMin(float a, float b)
{
	Fixed	fa(a);
	Fixed	fb(b);

	std::cout << "(" << fa << ", " << fb << ")" << " min:" << Fixed::min(fa, fb) << "-> " << ((Fixed::min(fa, fb)) == (std::min(a, b)) ? "OK" : "Error") << std::endl;
	std::cout << "(" << fa << ", " << fb << ")" << " max:" << Fixed::max(fa, fb) << "-> " << ((Fixed::max(fa, fb)) == (std::max(a, b)) ? "OK" : "Error") << std::endl;
}

void	testMaxMinConst(float a, float b)
{
	Fixed const	fa(a);
	Fixed const	fb(b);

	std::cout << "(" << fa << ", " << fb << ")" << " min:" << Fixed::min(fa, fb) << "-> " << ((Fixed::min(fa, fb)) == (std::min(a, b)) ? "OK" : "Error") << std::endl;
	std::cout << "(" << fa << ", " << fb << ")" << " max:" << Fixed::max(fa, fb) << "-> " << ((Fixed::max(fa, fb)) == (std::max(a, b)) ? "OK" : "Error") << std::endl;
}

void	testFractionalRange( int hide )
{
	int		d = Fixed::fractional_bits + 4;
	float	fl = 0.0f;
	Fixed	fi = Fixed(fl);
	Fixed	limit = Fixed(1.0f);
	Fixed	increment;

	increment.setRawBits(1);
	while (fi <= limit)
	{
		if (hide)
		{
			if (!(fi == Fixed(fl) && fi.toFloat() == fl))
				std::cout << std::setw(d) << fi << std::setw(d) << fl << ((fi == Fixed(fl) && fi.toFloat() == fl) ? "\tOK" : "\tError") << std::endl;
		}
		else
			std::cout << std::setw(d) << fi << std::setw(d) << fl << ((fi == Fixed(fl) && fi.toFloat() == fl) ? "\tOK" : "\tError") << std::endl;
		fi = fi + increment;
		fl += increment.toFloat();
	}
	
}

int main(int argc, char* argv[])
{
	float	a;
	float	b;

	if (argc == 1)
	{
		a = 2.5;
		b = 1.5;
	}
	else if (argc == 3)
	{
		a = atof(argv[1]);
		b = atof(argv[2]);
	}
	else
	{
		std::cerr << "Usage: " << argv[0] << " <float1> <float2>" << std::endl;
		return (1);
	}
	(void)a;
	(void)b;
	std::cout << "Testing Limits:" << std::endl;
	testLimits();
	std::cout << std::endl;

	/* std::cout << "Testing Addition:" << std::endl;
	testAddition(a, b);
	std::cout << std::endl;

	std::cout << "Testing Subtraction:" << std::endl;
	testSubtraction(a, b);
	std::cout << std::endl;

	std::cout << "Testing Multiplication:" << std::endl;
	testMultiplication(a, b);
	std::cout << std::endl;

	std::cout << "Testing Division:" << std::endl;
	testDivision(a, b);
	std::cout << std::endl;

	std::cout << "Testing Increment/Decrement:" << std::endl;
	testIncrementDecrement();
	std::cout << std::endl;

	std::cout << "Testing Comparison:" << std::endl;
	testComparison(a, b);
	std::cout << std::endl;

	std::cout << "Testing Max/Min:" << std::endl;
	testMaxMin(a, b);
	std::cout << std::endl;

	std::cout << "Testing Max/Min Const:" << std::endl;
	testMaxMinConst(a, b);
	std::cout << std::endl;

	std::cout << "Testing Range:" << std::endl;
	testFractionalRange(1);
	std::cout << std::endl; */

	return (0);
}