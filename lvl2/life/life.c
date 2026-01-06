#include "life.h"

int init_game(t_game *game, char *av[])
{
	game->width = atoi(av[1]);
	game->height = atoi(av[2]);
	game->iteration = atoi(av[3]);
	game->alive = '0';
	game->dead = ' ';
	game->i = 0;
	game->j = 0;
	game->draw = 0;
	game->board = (char**)malloc((game->height) * sizeof (char *));
	if (!game->board)
		return -1;
	for (int i = 0; i < game->height; i++)
	{
		game->board[i] = (char *)malloc((game->width) * sizeof(char));
		if (!game->board[i])
		{
			free_board(game);
			return (-1);
		}
		for (int j = 0; j < game->width; j++)
			game->board[i][j] = ' ';
	}
	return (0);
}

void print_board(t_game *game)
{
	for (int i = 0; i < game->height; i++)
	{
		for (int j = 0; j < game->width; j++)
			putchar(game->board[i][j]);
		putchar('\n');
	}
}

void free_board(t_game *game)
{
	if (game->board)
	{
		for (int i = 0; i < game->height; i++)
			if (game->board[i])
				free(game->board[i]);
		free(game->board);
	}
}
