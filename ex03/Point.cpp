/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:07:00 by math              #+#    #+#             */
/*   Updated: 2024/07/01 18:05:48 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(Fixed()), _y(Fixed()) { /*std::cout << "Point default constructor" << std::endl;*/ }

Point::Point( float _x, float _y) : _x(Fixed(_x)), _y(Fixed(_y)) { /*std::cout << "Point Float constructor" << std::endl;*/ }

Point::Point( Fixed _x, Fixed _y ) : _x(_x), _y(_y) { /*std::cout << "Point Fixed constructor" << std::endl;*/ }

Point::Point( Point const &obj ) : _x(obj._x), _y(obj._y) { /*std::cout << "Point Copy constructor" << std::endl;*/ }

Point::~Point( void ) { /*std::cout << "Point destructor" << std::endl;*/ }

Point	&Point::operator=(Point const &obj)
{
	if (this != &obj)
	{
		this->_x = obj._x;
		this->_y = obj._x;
	}
	return (*this);
}

Point	&Point::operator+(Point const &obj)
{
	this->_x = this->_x + obj._x;
	this->_y = this->_y + obj._y;
	return (*this);
}

Point	&Point::operator-(Point const &obj)
{
	this->_x = this->_x - obj._x;
	this->_y = this->_y - obj._y;
	return (*this);
}

Point	&Point::operator*(Point const &obj)
{
	this->_x = this->_x * obj._x;
	this->_y = this->_y * obj._y;
	return (*this);
}

bool	Point::operator==(Point const &obj) const
{
	return (this->_x == obj._x && this->_y == obj._y);
}

Fixed Point::x() const
{
	return (this->_x);
}

Fixed Point::y() const
{
	return (this->_y);
}

std::ostream	&operator<<(std::ostream &os, Point const &obj)
{
	os << "(" << obj.x() << ", " << obj.y() << ")";
	return (os);
}