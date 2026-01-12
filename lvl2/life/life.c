#include "life.h"

int init(t_game *game, char *av[])
{
	game->width = atoi(av[1]);
	game->height = atoi(av[2]);
	game->iterations = atoi(av[3]);
	game->alive = 'O';
	game->dead = ' ';
	game->draw = 0;
	game->i = 0;
	game->j = 0;
	game->board = (char **)malloc((game->height) * sizeof(char *));
	if (!(game->board))
		return -1;
	for (int i = 0; i < game->height; i++)
	{
		game->board[i] = (char *)malloc((game->width) * sizeof(char));
		if (!(game->board[i]))
			return (free_board(game), -1);
		for (int j = 0; j < game->width; j++)
			game->board[i][j] = ' ';
	}
	return (0);
}

void print_board(t_game *game)
{
	for(int i = 0; i < game->height; i++)
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
			free(game->board[i]);
		free(game->board);
	}
	game->board = NULL;
}

void fill_board(t_game *game)
{
	char buffer;
	int flag;

	while (read(STDIN_FILENO, &buffer, 1) == 1)
	{
		flag = 0;
		switch(buffer)
		{
			case 'w':
				if(game->i > 0)
				game->i--;
				break;
			case 's':
				if(game->i < (game->height - 1))
				game->i++;
				break;
			case 'a':
				if(game->j > 0)
				game->j--;
				break;
			case 'd':
				if(game->i < (game->width - 1))
				game->j++;
				break;
			case 'x':
				game->draw = !(game->draw);
				break;
			default:
				flag = 1;
				break;
		}
		if (game->draw && (flag == 0))
			if ((game->i >= 0) && (game->j >= 0) && (game->i < game->height) && (game->j < game->width))
				game->board[game->i][game->j] = game->alive;
	}
}

int count_neighbors(t_game *game, int i, int j)
{
	int count = 0;
	for(int di = -1; di < 2; di++)
	{
		for (int dj = -1; dj < 2; dj++)
		{
			if ((di == 0) && (dj == 0))
				continue;
			int ni = i + di;
			int nj = j + dj;
			if ((ni >= 0) && (nj >= 0) && (ni < game->height) && (nj < game->width))
				if(game->board[nj][ni] == game->alive)
					count++;
		}
	}
	return (count);
}

int play(t_game *game)
{
	char **temp = malloc((game->height) * sizeof(char *));
	if (!temp)
		return (-1);
	for (int i = 0; i < game->height; i++)
	{
		temp[i] = malloc((game->width) * sizeof(char));
		if (!(temp[i]))
			return (-1);
	}

	for (int i = 0; i < game->height; i++)
	{
		for (int j = 0; j < game->width; j++)
		{
			int neighbors = count_neighbors(game, i, j);
			if (game->board[i][j] == game->alive)
			{
				if (neighbors == 2 || neighbors == 3)
					temp[i][j] = game->alive;
				else
					temp[i][j] = game->dead;
			}
			else
			{
				if (neighbors == 3)
					temp[i][j] = game->alive;
				else
					temp[i][j] = game->dead;
			}
		}
	}
	free_board(game);
	game->board = temp;
	return (0);
}