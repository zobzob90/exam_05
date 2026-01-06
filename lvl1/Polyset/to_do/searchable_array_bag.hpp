/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:31:55 by eric              #+#    #+#             */
/*   Updated: 2026/01/06 14:48:11 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "searchable_bag.hpp"
#include "array_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag
{
	public:
		searchable_array_bag() {}
		searchable_array_bag(const searchable_array_bag& src) : array_bag(src) {}
		searchable_array_bag& operator=(const searchable_array_bag& src)
		{
			if (this != &src)
				array_bag::operator=(src);
			return *this;
		}
		~searchable_array_bag() {}

		bool has(int) const;
};
