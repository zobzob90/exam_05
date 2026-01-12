
#ifndef LIFE_H
#define LIFE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_game
{
	int width;
	int height;
	int iterations;
	int i;
	int j;
	char alive;
	char dead;
	int draw;
	char **board;

} t_game;


//init structure
int		init(t_game *game, char *av[]);

//board function
void	print_board(t_game *game);
void	fill_board(t_game *game);
void	free_board(t_game *game);

//int
int count_neighbour(t_game *game);
int play(t_game *game);

#endif
