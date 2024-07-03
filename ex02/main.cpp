/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:45 by math              #+#    #+#             */
/*   Updated: 2024/07/03 13:08:26 by math             ###   ########.fr       */
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
// int main( void )
// {
// 	Fixed a(2.25f);
// 	Fixed b(1.5f);
// 	Fixed c;

// 	std::cout << "a is:" << a << " " << "float:" << a.toFloat() << " int:" << a.toInt() << std::endl;
// 	std::cout << "b is:" << b << " " << "float:" << b.toFloat() << " int:" << b.toInt() << std::endl;

// 	/* SUM */
// 	c = a + b;
// 	std::cout << "c = a + b" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

// 	/* SUBS */
// 	c = a - b;
// 	std::cout << "c = a - b" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

// 	c = b - a;
// 	std::cout << "c = b - a" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

// 	c = b - ( a * (-1.0f));
// 	std::cout << "b - (-a))" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

// 	c = (b * (-1.0f)) - a;
// 	std::cout << "c = (-b) - a" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
	
// 	c = (b * (-1.0f)) - ( a * (-1.0f));
// 	std::cout << "(-b) - (-a))" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

// 	/* PROD */
// 	c = a * b;
// 	std::cout << "c = a * b" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

// 	c = b * ( a * (-1.0f));
// 	std::cout << "b * (-a))" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

// 	c = (b * (-1.0f)) * a;
// 	std::cout << "c = (-b) * a" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
	
// 	c = (b * (-1.0f)) * ( a * (-1.0f));
// 	std::cout << "(-b) * (-a))" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

// 	/* DIV */
// 	c = a * b;
// 	std::cout << "c = a / b" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

// 	c = b * ( a * (-1.0f));
// 	std::cout << "b / (-a))" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

// 	c = (b * (-1.0f)) / a;
// 	std::cout << "c = (-b) / a" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
	
// 	c = (b * (-1.0f)) / ( a * (-1.0f));
// 	std::cout << "(-b) / (-a))" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

// 	c = (b * (0.0f)) / ( a * (-1.0f));
// 	std::cout << "(b * 0) / (-a))" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

// 	c = (b) / ( a * 0.0f);
// 	std::cout << "b / (a * 0)" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

// 	/* INCREMENT/DECREMENT */
// 	c++;
// 	std::cout << "c++" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
// 	std::cout << "++c" << std::endl;
// 	std::cout << "c is:" << ++c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

// 	c--;
// 	std::cout << "c--" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
// 	std::cout << "--c" << std::endl;
// 	std::cout << "c is:" << --c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
	
// 	c--;
// 	std::cout << "c--" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
// 	c--;
// 	std::cout << "c--" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
// 	c--;
// 	std::cout << "c--" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
// 	c++;
// 	std::cout << "c++" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
// 	c++;
// 	std::cout << "c++" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;
// 	c++;
// 	std::cout << "c++" << std::endl;
// 	std::cout << "c is:" << c << " " << "float:" << c.toFloat() << " int:" << c.toInt() << std::endl;

// 	/* COMPARISON */
// 	std::cout << "a == b " << (a == b) << std::endl;
// 	std::cout << "a == a " << (a == a) << std::endl;
// 	std::cout << "a != b " << (a != b) << std::endl;
// 	std::cout << "a != a " << (a != a) << std::endl;
// 	std::cout << "a < b " << (a < b) << std::endl;
// 	std::cout << "a > b " << (a > b) << std::endl;
// 	std::cout << "a < (b * (-1.0f)) " << (a < (b * (-1.0f))) << std::endl;
// 	std::cout << "a > (b * (-1.0f)) " << (a > (b * (-1.0f))) << std::endl;
// 	std::cout << "(a * (-1.0f)) < (b * (-1.0f)) " << ((a * (-1.0f)) < (b * (-1.0f))) << std::endl;
// 	std::cout << "(a * (-1.0f)) > (b * (-1.0f)) " << ((a * (-1.0f)) > (b * (-1.0f))) << std::endl;
// 	std::cout << "a <= b " << (a <= b) << std::endl;
// 	std::cout << "a >= b " << (a >= b) << std::endl;
// 	std::cout << "a <= (b * (-1.0f)) " << (a <= (b * (-1.0f))) << std::endl;
// 	std::cout << "a >= (b * (-1.0f)) " << (a <= (b * (-1.0f))) << std::endl;

// 	return (0);
// }


// Helper function to print test results
void printTestResult(const std::string& operation, const Fixed& a, const Fixed& b, const Fixed& result, float expected) {
    std::cout << operation << " (" << a << " " << operation << " " << b << ") = " << result
              << " (Expected: " << expected << ") -> "
              << (result.toFloat() == expected ? "OK" : "Error") << std::endl;
}

void testAddition() {
    Fixed a(2.25f);
    Fixed b(1.5f);
    Fixed result;

    result = a + b;
    printTestResult("+", a, b, result, 3.75f);
}

void testSubtraction() {
    Fixed a(2.25f);
    Fixed b(1.5f);
    Fixed result;

    result = a - b;
    printTestResult("-", a, b, result, 0.75f);

    result = b - a;
    printTestResult("-", b, a, result, -0.75f);

    result = b - (a * -1.0f);
    printTestResult("-", b, a * -1.0f, result, 3.75f);

    result = (b * -1.0f) - a;
    printTestResult("-", b * -1.0f, a, result, -3.75f);

    result = (b * -1.0f) - (a * -1.0f);
    printTestResult("-", b * -1.0f, a * -1.0f, result, -0.75f);
}

void testMultiplication() {
    Fixed a(2.25f);
    Fixed b(1.5f);
    Fixed result;

    result = a * b;
    printTestResult("*", a, b, result, 3.375f);

    result = b * (a * -1.0f);
    printTestResult("*", b, a * -1.0f, result, -3.375f);

    result = (b * -1.0f) * a;
    printTestResult("*", b * -1.0f, a, result, -3.375f);

    result = (b * -1.0f) * (a * -1.0f);
    printTestResult("*", b * -1.0f, a * -1.0f, result, 3.375f);
}

void testDivision() {
    Fixed a(2.25f);
    Fixed b(1.5f);
    Fixed result;

    result = a / b;
    printTestResult("/", a, b, result, 1.5f);

    result = b / (a * -1.0f);
    printTestResult("/", b, a * -1.0f, result, -0.66666667f);

    result = (b * -1.0f) / a;
    printTestResult("/", b * -1.0f, a, result, -0.66666667f);

    result = (b * -1.0f) / (a * -1.0f);
    printTestResult("/", b * -1.0f, a * -1.0f, result, 0.66666667f);

    result = (b * 0.0f) / (a * -1.0f);
    printTestResult("/", b * 0.0f, a * -1.0f, result, 0.0f);

    // Handling division by zero
    try {
        result = b / (a * 0.0f);
        std::cout << "b / (a * 0) = " << result << " -> Error (Division by zero not handled)" << std::endl;
    } catch (...) {
        std::cout << "b / (a * 0) -> OK (Division by zero handled)" << std::endl;
    }
}

void testIncrementDecrement() {
    Fixed c(1.5f);
    std::cout << "Initial c: " << c << std::endl;

    c++;
    std::cout << "c++: " << c << std::endl;

    ++c;
    std::cout << "++c: " << c << std::endl;

    c--;
    std::cout << "c--: " << c << std::endl;

    --c;
    std::cout << "--c: " << c << std::endl;
}

void testComparison() {
    Fixed a(2.25f);
    Fixed b(1.5f);

    std::cout << "a == b: " << (a == b) << " -> " << (a == b ? "OK" : "Error") << std::endl;
    std::cout << "a == a: " << (a == a) << " -> " << (a == a ? "OK" : "Error") << std::endl;
    std::cout << "a != b: " << (a != b) << " -> " << (a != b ? "OK" : "Error") << std::endl;
    std::cout << "a != a: " << (a != a) << " -> " << (a != a ? "OK" : "Error") << std::endl;
    std::cout << "a < b: " << (a < b) << " -> " << (a < b ? "OK" : "Error") << std::endl;
    std::cout << "a > b: " << (a > b) << " -> " << (a > b ? "OK" : "Error") << std::endl;
    std::cout << "a < (b * -1.0f): " << (a < (b * -1.0f)) << " -> " << (a < (b * -1.0f) ? "OK" : "Error") << std::endl;
    std::cout << "a > (b * -1.0f): " << (a > (b * -1.0f)) << " -> " << (a > (b * -1.0f) ? "OK" : "Error") << std::endl;
    std::cout << "(a * -1.0f) < (b * -1.0f): " << ((a * -1.0f) < (b * -1.0f)) << " -> " << ((a * -1.0f) < (b * -1.0f) ? "OK" : "Error") << std::endl;
    std::cout << "(a * -1.0f) > (b * -1.0f): " << ((a * -1.0f) > (b * -1.0f)) << " -> " << ((a * -1.0f) > (b * -1.0f) ? "OK" : "Error") << std::endl;
    std::cout << "a <= b: " << (a <= b) << " -> " << (a <= b ? "OK" : "Error") << std::endl;
    std::cout << "a >= b: " << (a >= b) << " -> " << (a >= b ? "OK" : "Error") << std::endl;
    std::cout << "a <= (b * -1.0f): " << (a <= (b * -1.0f)) << " -> " << (a <= (b * -1.0f) ? "OK" : "Error") << std::endl;
    std::cout << "a >= (b * -1.0f): " << (a >= (b * -1.0f)) << " -> " << (a >= (b * -1.0f) ? "OK" : "Error") << std::endl;
}

int main() {
    std::cout << "Testing Addition:" << std::endl;
    testAddition();
    std::cout << std::endl;

    std::cout << "Testing Subtraction:" << std::endl;
    testSubtraction();
    std::cout << std::endl;

    std::cout << "Testing Multiplication:" << std::endl;
    testMultiplication();
    std::cout << std::endl;

    std::cout << "Testing Division:" << std::endl;
    testDivision();
    std::cout << std::endl;

    std::cout << "Testing Increment/Decrement:" << std::endl;
    testIncrementDecrement();
    std::cout << std::endl;

    std::cout << "Testing Comparison:" << std::endl;
    testComparison();
    std::cout << std::endl;

    return 0;
}