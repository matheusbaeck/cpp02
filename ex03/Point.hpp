/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:59 by math              #+#    #+#             */
/*   Updated: 2024/07/01 17:13:23 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H__
# define POINT_H__

# include "Fixed.hpp"

class Point
{
	protected:
		Fixed	_x;
		Fixed	_y;
	public:
		Point( void );
		Point( Fixed _x, Fixed _y );
		Point( float _x, float _y);
		Point( Point const &src );
		~Point( void );

		Point	&operator=(Point const &obj);
		Point	&operator+(Point const &obj);
		Point	&operator-(Point const &obj);
		Point	&operator*(Point const &obj);
		bool	operator==(Point const &obj) const;

		Fixed x() const;
		Fixed y() const;
};

std::ostream	&operator<<(std::ostream &os, Point const &obj);

#endif