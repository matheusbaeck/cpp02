/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:59 by math              #+#    #+#             */
/*   Updated: 2024/07/06 13:29:49 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H__
# define FIXED_H__

# include "limits.h"
# include <iostream>
# include <iomanip>
# include <cstring> //std::memcpy
# include <cmath> //atof



class Fixed
{
	private:
		int	_value;
	public:
		static const int	fractional_bits = 8;
		Fixed( void );
		Fixed( int value );
		Fixed( float value );
		Fixed( Fixed const &src );
		~Fixed( void );

		Fixed	&operator=(Fixed const &obj);
		Fixed	operator+(Fixed const &obj) const;
		Fixed	operator-(Fixed const &obj) const;
		Fixed	operator*(Fixed const &obj) const;
		Fixed	operator/(Fixed const &obj) const;
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
		bool	operator>(Fixed const &obj) const;
		bool	operator<(Fixed const &obj) const;
		bool	operator>=(Fixed const &obj) const;
		bool	operator<=(Fixed const &obj) const;
		bool	operator==(Fixed const &obj) const;
		bool	operator!=(Fixed const &obj) const;

		int		getRawBits( void ) const;
		void	setRawBits( int newValue );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed		&min(Fixed& a, Fixed& b);
		static Fixed		&max(Fixed& a, Fixed& b);
		static Fixed const	&min(Fixed const &a, Fixed const &b);
		static Fixed const	&max(Fixed const &a, Fixed const &b);
};

std::ostream	&operator<<(std::ostream &os, Fixed const &obj);

std::string	printBit(int nb);
std::string	printBit(float f);

#endif
