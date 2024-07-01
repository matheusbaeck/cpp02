/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Triangle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:59 by math              #+#    #+#             */
/*   Updated: 2024/07/01 18:36:34 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H__
# define TRIANGLE_H__

# include <iostream>
# include <bitset>
# include <cstring>
# include <cmath>
# include "Point.hpp"

class Triangle
{
	private:
		Point	_A;
		Point	_B;
		Point	_C;
		bool	_exist;

	public:
		Triangle( void );
		Triangle( Point _A, Point _B, Point _C );
		Triangle( Triangle const &src );
		~Triangle( void );

		Point	vA() const;
		Point	vB() const;
		Point	vC() const;
		Fixed	getArea() const;
		bool	cointain( Point P ) const;

		Triangle	&operator=(Triangle const &obj);
};

std::ostream	&operator<<(std::ostream &os, Triangle const &obj);

#endif