/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:59 by math              #+#    #+#             */
/*   Updated: 2024/06/03 18:45:07 by math             ###   ########.fr       */
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
	int	_value;
	public:
		static const int	fractional_bits = 8;
		Fixed( int value );
		Fixed( float value );
		Fixed( void );
		Fixed( Fixed const &src);
		~Fixed( void );

		Fixed			&operator=(Fixed const &rhc);

		int		getRawBits( void ) const;
		void	setRawBits( int newValue );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
};

std::ostream	&operator<<(std::ostream &os, Fixed const &obj);

void	printBit(int nb);
void	printBit(float f);

#endif