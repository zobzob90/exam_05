/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:34:15 by eric              #+#    #+#             */
/*   Updated: 2026/01/06 14:48:02 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "searchable_bag.hpp"
#include "tree_bag.hpp"

class searchable_tree_bag : public tree_bag, public searchable_bag
{
	private:
		bool search(node *node, int value) const;
	public:
		searchable_tree_bag() {}
		searchable_tree_bag(const searchable_tree_bag& src) : tree_bag(src) {}
		searchable_tree_bag& operator=(const searchable_tree_bag& src)
		{
			if (this != &src)
				tree_bag::operator=(src);
			return *this;
		}
		~searchable_tree_bag() {}

		bool has(int) const;
};