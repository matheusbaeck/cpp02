/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:59 by math              #+#    #+#             */
/*   Updated: 2024/07/01 22:14:16 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H__
# define FIXED_H__

# include <iostream>
# include <bitset>
# include <cstring>
# include <cmath>

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
		Fixed	&operator+(Fixed const &obj);
		Fixed	&operator-(Fixed const &obj);
		Fixed	&operator*(Fixed const &obj);
		Fixed	&operator/(Fixed const &obj);
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
};

std::ostream	&operator<<(std::ostream &os, Fixed const &obj);

void	printBit(int nb);
void	printBit(float f);

#endif