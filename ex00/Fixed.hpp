/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: math <math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:30:59 by math              #+#    #+#             */
/*   Updated: 2024/07/01 21:18:52 by math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H__
# define FIXED_H__

# include <iostream>

class Fixed
{
	private:
		int	_value;
	public:
		static const int	fractional_bits = 8;
		Fixed( void );
		Fixed( Fixed const &src);
		~Fixed( void );

		Fixed			&operator=(Fixed const &obj);

		int		getRawBits( void ) const;
		void	setRawBits( int newValue );
};

std::ostream	&operator<<(std::ostream &os, Fixed const &obj);

#endif