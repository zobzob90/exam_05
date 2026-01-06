/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:39:21 by eric              #+#    #+#             */
/*   Updated: 2026/01/06 14:50:22 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_tree_bag.hpp"

bool searchable_tree_bag::search(node *node, int value) const
{
	if (node == nullptr)
		return (false);
	if (node->value == value)
		return (true);
	else if (value < node->value)
		return (search(node->l, value));
	else
		return (search(node->r, value));	
}

bool searchable_tree_bag::has(int value) const
{
	return (search(this->tree, value));
}
