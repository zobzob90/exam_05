#ifndef LIFE_H
# define LIFE_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_game
{
	int width;
	int height;
	int iteration;
	char alive;
	char dead;
	int i;
	int j;
	int draw;
	char **board;
} t_game;

//init_function
int		init_game(t_game* game, char *av[]);

//board function
void	print_board(t_game* game);
void	fill_board(t_game* game);
void	free_board(t_game* game);

//utils
int count_neighbors(t_game* game, int i, int j);

//main function
int 	play(t_game* game);

#endif
