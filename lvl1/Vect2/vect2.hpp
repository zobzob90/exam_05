/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:16:02 by eric              #+#    #+#             */
/*   Updated: 2026/01/06 15:40:17 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <string>
#include <iostream>

class vect2
{
	private:
		std::vector<int> _container;
	public:
		vect2() : _container(2, 0) {}
		vect2(int v1, int v2) : _container(2)
		{
			_container[0] = v1;
			_container[1] = v2;
		}
		vect2(const vect2& src) : _container(src._container) {}
		vect2& operator=(const vect2& src)
		{
			if (this != &src)
				_container = src._container;
			return *this;
		}		
		~vect2() {}

		int get_container(int idx) const{ return (_container[idx]);}
		int& operator[](int idx) {return _container[idx];}
		const int& operator[] (int idx) const {return _container[idx];}

		vect2 operator-() const
		{
			return (vect2(-_container[0], -_container[1]));
		}

		//op
		vect2 operator+(int add) const {return(vect2(_container[0] + add, _container[1] + add));}
		vect2 operator+(const vect2 &addon) const {return(vect2(_container[0] + addon._container[0], _container[1] + addon._container[1]));}
		
		vect2 operator-(int minus) const {return(vect2(_container[0] - minus, _container[1] - minus));}
		vect2 operator-(const vect2 &minuson) const {return(vect2(_container[0] - minuson._container[0], _container[1] - minuson._container[1]));}

		vect2 operator*(int multi) const {return(vect2(_container[0] * multi, _container[1] * multi));}
		vect2 operator*(const vect2 &multion) const {return(vect2(_container[0] * multion._container[0], _container[1] * multion._container[1]));}

		//Incr + Decr
		vect2& operator++() {++_container[0]; ++_container[1]; return *this;}
		vect2& operator--() {--_container[0]; --_container[1]; return *this;}

		vect2 operator++(int) {vect2 temp = *this; ++(*this); return temp;}
		vect2 operator--(int) {vect2 temp = *this; --(*this); return temp;}

		// Compound
		vect2& operator+=(int add) {_container[0] += add; _container[1] += add; return *this;}
		vect2& operator+=(const vect2& src) {_container[0] += src._container[0]; _container[1] += src._container[1]; return *this;}

		vect2& operator-=(int add) {_container[0] -= add; _container[1] -= add; return *this;}
		vect2& operator-=(const vect2& src) {_container[0] -= src._container[0]; _container[1] -= src._container[1]; return *this;}

		vect2& operator*=(int add) {_container[0] *= add; _container[1] *= add; return *this;}
		vect2& operator*=(const vect2& src) {_container[0] *= src._container[0]; _container[1] *= src._container[1]; return *this;}

		//comparison
		bool operator==(const vect2& src) {return (_container[0] == src._container[0] && _container[1] == src._container[1]);}
		bool operator!=(const vect2& src) {return (!(*this == src));}
		
		// surcharge
		friend vect2 operator*(int numb, const vect2& src)
		{
			return (src *numb);
		}

		friend std::ostream& operator<<(std::ostream& out, const vect2& src)
		{
			out << "{" << src._container[0] << ", " << src._container[1] << "}";
			return out;
		}
};	