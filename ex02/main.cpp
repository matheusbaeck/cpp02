/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:45 by math              #+#    #+#             */
/*   Updated: 2024/07/09 18:52:19 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>
#include "limits.h"

#include <string>
#include <sstream>

void printWelcomeMessage() {
    std::cout << "   _____ _        _                _______        _     _       _             \n"
                 "  / ____| |      (_)              |__   __|      | |   (_)     | |            \n"
                 " | (___ | |_ _ __ _ _ __   __ _ ______| | ___  __| |    _ _ __ | |_ ___  _ __ \n"
                 "  \\___ \\| __| '__| | '_ \\ / _` |_  / _` |/ _ \\/ _` |   | | '_ \\| __/ _ \\| '__|\n"
                 "  ____) | |_| |  | | | | | (_| |/ / (_| |  __/ (_| |   | | | | | || (_) | |   \n"
                 " |_____/ \\__|_|  |_|_| |_|\\__,_/___\\__,_|\\___|\\__,_|   |_|_| |_|\\__\\___/|_|   \n"
                 "                                                                               \n"
                 "   ____  _       _   _  __      _______          _                            \n"
                 "  / __ \\| |     | | (_)/ _|    |__   __|        | |                           \n"
                 " | |  | | | ___ | |_ _| |_ _   _ _| | ___   ___ | |                           \n"
                 " | |  | | |/ _ \\| __| |  _| | | | | |/ _ \\ / _ \\| |                           \n"
                 " | |__| | | (_) | |_| | | | |_| | | | (_) | (_) | |                           \n"
                 "  \\____/|_|\\___/ \\__|_|_|  \\__,_| |_|\\___/ \\___/|_|                           \n"
                 "                                                                               \n"
                 " =========================================================================== \n"
                 "|                                                                            |\n"
                 "|                           WELCOME TO FIXED CLASS                           |\n"
                 "|                                                                            |\n"
                 "|                    Initialization & Testing in Progress                    |\n"
                 "|                                                                            |\n"
                 "|                  Converting Floats to Fixed-Point Numbers                  |\n"
                 " =========================================================================== \n";
}

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

void	testFixed( int	nb )
{
	Fixed it(nb);
	Fixed fl(static_cast<float>(nb));

	std::cout << "Fixed(INT): ";

	if (nb != it.toInt())
		std::cout << " nb != it.toInt() " << nb << " " << it.toInt() << std::endl;
	if (nb != fl.toInt())
		std::cout << " nb != fl.toInt() " << nb << " " << fl.toInt() << std::endl;
	
	else if (fl != it)
		std::cout << " fl == it " << fl << " " << it << std::endl;
	else if (fl.getRawBits() != it.getRawBits())
		std::cout << " fl.getRawBits() == it.getRawBits() " << fl.getRawBits() << " " << it.getRawBits() << std::endl;
	else if (fl.toFloat() != it.toFloat())
		std::cout << " fl.toFloat() != it.toFloat()" << fl.toFloat() << " " << it.toFloat() << std::endl;
	else if (fl.toInt() != it.toInt())
		std::cout << " fl.toInt() != it.toInt() " << fl.toInt() << " " << it.toInt() << std::endl;

	else if (static_cast<float>(nb) != fl.toFloat())
		std::cout << " static_cast<float>(nb) != fl.toFloat() " << static_cast<float>(nb) << " " << fl.toFloat() << std::endl;
	else if (static_cast<float>(nb) != it.toFloat())
		std::cout << " static_cast<float>(nb) != it.toFloat() " << static_cast<float>(nb) << " " << fl.toInt() << std::endl;
	else
	{
		std::cout << printBit(nb) << "\t" << std::setw(8) << std::left << nb << " OK!" << std::endl;
		return ;
	}
	std::cout << printBit(nb) << "\tasInt:" << std::setw(8) << nb << " asFloat:" << static_cast<float>(nb) << std::endl;
	std::cout << printBit(fl.getRawBits()) << "\ttoInt:" << std::setw(8) << fl.toInt()  << " toFloat:" << fl.toFloat() << std::endl;
	std::cout << printBit(it.getRawBits()) << "\ttoInt:" << std::setw(8) << it.toInt()  << " toFloat:" << it.toFloat() << std::endl;
	std::cout << std::endl;
}

void	testFixed( float nb )
{
	float	fract = nb - static_cast<int>(nb); 
	Fixed	fl(nb);
	Fixed	it(static_cast<int>(nb));

	std::cout << "Fixed(FLOAT): ";
	if (nb != fl.toFloat())
		std::cout << " nb != fl.toFloat() " << nb << " " << fl.toFloat() << std::endl;
	else if ((nb - fract) != it.toFloat())
		std::cout << " (nb - fract) != it.toFloat() " << (nb - fract) << " " << it.toFloat() << std::endl;

	else if ((fl.getRawBits() & ~((1 << Fixed::fractional_bits) - 1)) != (it.getRawBits() & ~((1 << Fixed::fractional_bits) - 1)) &&
				(fl.getRawBits() & ~((1 << Fixed::fractional_bits) - 1)) != (1 << 31))
		std::cout << " (fl.getRawBits() & ~((1 << Fixed::fractional_bits) - 1)) != (it.getRawBits() & ~((1 << Fixed::fractional_bits) - 1)) " << (fl.getRawBits() & ~((1 << Fixed::fractional_bits) - 1)) << " " << (it.getRawBits() & ~((1 << Fixed::fractional_bits) - 1)) << std::endl;
	else if (fl.toInt() != it.toInt())
		std::cout << " fl.toInt() != it.toInt() " << fl.toInt() << " " << it.toInt() << std::endl;
	// else if ((fl - (fl - it)) != it && (fl + (fl - it)) != it)
	// 	std::cout << " (fl -+ (fl - it)) != it " << "fl="<< fl  << "it=" << it << " space " << (fl - (fl - it)) << "|" << (fl + (fl - it)) << " " << it << std::endl;
	// else if ((fl - (fl - it)).toFloat() != it.toFloat() && (fl + (fl - it)).toFloat() != it.toFloat())
	// 	std::cout << " (fl -+ (fl - it)).toFloat() != it.toFloat() " << (fl - (fl - it)).toFloat() << "|" << (fl - (fl - it)).toFloat() << " " << it.toFloat() << std::endl;
	

	else if (static_cast<int>(nb) != it.toInt())
		std::cout << " static_cast<int>(nb) != it.toInt() " << static_cast<int>(nb) << " " << it.toInt() << std::endl;
	else if (static_cast<int>(nb) != fl.toInt())
		std::cout << " static_cast<int>(nb) != fl.toInt() " << static_cast<int>(nb) << " " << fl.toInt() << std::endl;
	// else if (std::abs(fl.toFloat() - nb) < (1.0 / (1 << Fixed::fractional_bits)))
	// 	std::cout << " std::abs(fl.toFloat() - nb) < (1.0 / (1 << Fixed::fractional_bits)) " << std::abs(fl.toFloat() - nb) << " " << (1.0 / (1 << Fixed::fractional_bits)) << std::endl;
	else
	{
		std::cout << printBit(nb) << "\t" << std::setw(8) << std::left << nb << " OK!" << std::endl;
		return ;
	}
	std::cout << printBit(nb) << "\tasInt:" << static_cast<int>(nb) << " asFloat:" << nb << std::endl;
	std::cout << printBit(fl.getRawBits()) << "\ttoInt:" << fl.toInt() << " toFloat:" << fl.toFloat() << std::endl;
	std::cout << printBit(fl.toFloat()) << std::endl;
	std::cout << printBit(it.getRawBits()) << "\ttoInt:" << it.toInt() << " toFloat:" << it.toFloat() << std::endl;
	std::cout << printBit(it.toFloat()) << std::endl;
	std::cout << std::endl;
}

void	printTestResult(const std::string &operation, const Fixed &a, const Fixed &b, const Fixed &result, float expected)
{
	std::cout << a << " " << operation << " " << b << " = " << result << " (Expected: " << expected << ")-> " << (result.toFloat() == expected ? "OK" : "Error") << std::endl;
}

void	testLimitsInt()
{
	int	nb;

	std::cout << std::endl << "Testing Limits +Int:" << std::endl;
	for (size_t i = 0; i < (31 - Fixed::fractional_bits); i++)
	{
		nb = (1 << i);
		testFixed(nb);
	}
	for (size_t i = 2; i < (32 - Fixed::fractional_bits); i++)
	{
		nb = ((1 << i) -1);
		testFixed(nb);
	}
	std::cout << std::endl << "Testing Limits -Int:" << std::endl;
	for (size_t i = 0; i < (32 - Fixed::fractional_bits); i++)
	{
		nb = (1 << i);
		testFixed(nb * (-1));
	}
	for (size_t i = 0; i < (32 - Fixed::fractional_bits); i++)
	{
		nb = ((1 << i) -1);
		testFixed(nb * (-1));
	}
}

void	testLimitsFloat()
{
	/* int		temp;
	// int		extra[] = {0, ~(0)};
	float	nb;
	int 	exp = 127; */
	int temp;
	float nb;

	
	std::cout << std::endl << "Testing Limits Natural +Float:" << std::endl;
	for (size_t i = 0; i < (31 - Fixed::fractional_bits); i++)
	{
		nb = (1 << i);
		testFixed(static_cast<float>(nb));
	}
	for (size_t i = 2; i < (32 - Fixed::fractional_bits); i++)
	{
		nb = ((1 << i) -1);
		testFixed(static_cast<float>(nb));
	}

	std::cout << std::endl << "Testing Limits Natural -Float:" << std::endl;
	for (size_t i = 0; i < (32 - Fixed::fractional_bits); i++)
	{
		nb = (1 << i);
		testFixed(static_cast<float>(nb) * (-1));
	}
	for (size_t i = 0; i < (32 - Fixed::fractional_bits); i++)
	{
		nb = ((1 << i) -1);
		testFixed(static_cast<float>(nb) * (-1));
	}

	std::cout << std::endl << "Testing Limits Natural +FloatExp:" << std::endl;
	for (int exp = (127 - Fixed::fractional_bits); exp <= (127 + Fixed::fractional_bits); exp++)
	{
		for (int i =  0; i < 23; i++)
		{
			if (i <= (Fixed::fractional_bits + (exp - 127) - 1))
			{
				temp = ((exp << 23) | (1 << (22 - i)));
				std::memcpy(&nb, &temp, sizeof(float));
				testFixed(nb);
			}
		}
	}
	std::cout << std::endl << "Testing Limits Natural -FloatExp:" << std::endl;
	for (int exp = (127 - Fixed::fractional_bits); exp <= (127 + Fixed::fractional_bits); exp++)
	{
		for (int i =  0; i < 23; i++)
		{
			if (i <= (Fixed::fractional_bits + (exp - 127) - 1))
			{
				temp = ((exp << 23) | (1 << (22 - i)));
				std::memcpy(&nb, &temp, sizeof(float));
				testFixed(nb * (-1));
			}
		}
	}

	

	// for (size_t i = 0; i < 32; i++)
	// {
	// 	temp = (1 << i) - 1;
	// 	std::memcpy(&nb, &temp, sizeof(float));
	// 	testFixed(nb);
	// }
	// for (size_t i = 0; i < 2; i++)
	// {
	// 	temp = extra[i];
	// 	std::memcpy(&nb, &temp, sizeof(float));
	// 	testFixed(nb);
	// }
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
	printWelcomeMessage();
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
	testFractionalRange(0);
	std::cout << std::endl; */

	//testLimitsInt();
	testLimitsFloat();

	return (0);
}
