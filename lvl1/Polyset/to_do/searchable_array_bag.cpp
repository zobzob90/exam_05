/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:36:17 by eric              #+#    #+#             */
/*   Updated: 2026/01/06 14:47:18 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_array_bag.hpp"

bool searchable_array_bag::has(int value) const
{
	for (int i = 0; i < this->size; i++)
		if (this->data[i] == value)
			return (true);
	return (false);
}
