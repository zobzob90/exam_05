/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:42:42 by eric              #+#    #+#             */
/*   Updated: 2026/01/06 14:54:09 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "searchable_bag.hpp"

class set
{
	private: 
		searchable_bag& bag;
	public:
		set(searchable_bag& b) : bag(b) {}
		set(const set& src) : bag(src.bag) {}
		set& operator=(const set& src)
		{
			if (this != &src)
				bag.clear();
			return *this;
		}
		~set() = default;

		void print() const {return bag.print();}
		void clear() {return bag.clear();}
		bool has(int value) const {return bag.has(value);}

		searchable_bag& get_bag() {return bag;}
		const searchable_bag& get_bag() const {return bag;}

		void insert(int item)
		{
			if (!(bag.has(item)))
				bag.insert(item);
		}		

		void insert(int *items, int count)
		{
			for (int i = 0; i < count; i++)
				insert(items[i]);
		}
};