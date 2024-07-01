/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:44:05 by math              #+#    #+#             */
/*   Updated: 2024/07/01 18:51:59 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Triangle.hpp"

Triangle::Triangle( void ) : _A(Point(0.0f, 0.0f)), _B(Point(42.0f, 0.0f)), _C(Point(0.0f, 42.0f)), _exist(true) { /*std::cout << "Triangle Default constructor" << std::endl;*/ };

Triangle::Triangle( Point _A, Point _B, Point _C ) : _A(_A), _B(_B), _C(_C)
{
	if (_A == _B || _A == _C || _C == _B)
	{
		std::cout << "not a valid triangle" << std::endl;
		this->_exist = false;
	}
	else
		this->_exist = true;
	// std::cout << "Triangle Piont constructor" << std::endl; 
}

Triangle::Triangle( Triangle const &src ) { *this = src; /*std::cout << "Triangle Copy constructor" << std::endl;*/ }

Triangle::~Triangle( void ) { /*std::cout << "Triangle destructor" << std::endl;*/ }

Triangle	&Triangle::operator=(Triangle const &obj)
{
	this->_A = obj._A;
	this->_B = obj._B;
	this->_C = obj._C;
	this->_exist = obj._exist;
	return (*this);
}

Point	Triangle::vA() const
{
	return (this->_A);
}
Point	Triangle::vB() const
{
	return (this->_B);
}
Point	Triangle::vC() const
{
	return (this->_C);
}

Fixed	Triangle::getArea() const
{
	Fixed	area = ((this->_B.x() - this->_A.x()) * (this->_C.y() - this->_A.y()) - (this->_B.y() - this->_A.y()) * (this->_C.x() - this->_A.x())) / 2.0f;

	if (area < 0)
		area = area * (-1);
	return (area);
}

bool	Triangle::cointain( Point P ) const
{
	Triangle	pab(P, this->_A, this->_B);
	Triangle	pbc(P, this->_B, this->_C);
	Triangle	pca(P, this->_C, this->_A);

	if (!this->_exist || this->getArea() == 0)
		return (false);
	if (!(pab._exist && pbc._exist && pca._exist))
	{
		std::cout << "point coincid with a vertice!" << std::endl;
		return (true);
	}
	if (this->getArea() == (pab.getArea() + pbc.getArea() + pca.getArea()))
	{
		std::cout << pab.getArea() << " " << pbc.getArea() << " " << pca.getArea() << std::endl; 
		if (pab.getArea() == 0 || pbc.getArea() == 0 || pca.getArea() == 0)
		{
			std::cout << "point coincid with a side!" << std::endl;
			return (true);
		}
		std::cout << "point is inside triangle!" << std::endl;
		return (true);
	}
	return (false);
}

std::ostream	&operator<<(std::ostream &os, Triangle const &obj)
{
	os << "[" << obj.vA() << ", " << obj.vB() << ", " << obj.vC() << "]";
	return (os);
}