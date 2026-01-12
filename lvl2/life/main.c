/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 21:38:11 by eric              #+#    #+#             */
/*   Updated: 2026/01/11 21:40:32 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

int main(int ac, char *av[])
{
	if (ac < 4)
		return (-1);
	t_game game;

	if (init(&game, av) == -1)
		return (-1);
	fill_board(&game);
	for (int i = 0; i < game.iterations; i++)
	{
		if (play(&game) == -1)
			return (free_board(&game), -1);
	}
	print_board(&game);
	free_board(&game);
	return (0);
}
