/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:48:01 by eric              #+#    #+#             */
/*   Updated: 2025/09/29 16:27:16 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
#include <sstream>

class bigint
{
	private :
		std::string _value;
		void remove_leading_zero();	
	
	public :
		bigint() : _value("0") {} // constructeur
		bigint(unsigned long long number)
		{
			std::ostringstream oss;
			oss << number;
			_value = oss.str();
		}
		bigint(const bigint& src) : _value(src._value) {}
		bigint& operator=(const bigint& src)
		{
			if (this != &src)
				_value = src._value;
			return (*this);
		}
		
		//arithmetic op
		bigint operator+(const bigint& src) const;
		bigint& operator+=(const bigint& src)
		{
			*this = *this + src;
			return *this;
		}

		// Digit shif op (base 10)
		bigint operator<<(size_t shift) const;
		bigint& operator<<=(size_t shift);
		bigint operator>>(size_t shift) const;
		bigint& operator>>=(size_t shift);

		// Comparison
		bool operator<(const bigint& src) const;
		bool operator>(const bigint& src) const 
		{
			return (src < *this);
		}
		bool operator<=(const bigint& src) const
		{
			return !(src < *this);
		}
		bool operator>=(const bigint& src) const
		{
			return !(*this < src);
		}
		bool operator==(const bigint& src)
		{
			return (_value == src._value);
		}
		bool operator!=(const bigint& src)
		{
			return (_value != src._value);
		}
		
		//incr
		bigint& operator++();
		bigint operator++(int);

		friend std::ostream& operator<<(std::ostream& os, const bigint& src)
		{
			os << src._value;
			return os;
		}
} ;

#endif