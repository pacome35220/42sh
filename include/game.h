/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** game.h
*/

#pragma once

#include <ncurses.h>
#include <stdlib.h>
#include "shell.h"

/*
**	POWER4
*/

int	my_power4(shell_t *shell, int argc, char **argv);

char	test_win(char tab[7][6]);
size_t	ia(char tab[7][6]);

/*
**	SNAKE
*/

#define WIDTH 20
#define HEIGHT 20

#define PUT_ITEM(game) ((game).map[rand() % (WIDTH - 2) + 1]\
			[rand() % (HEIGHT - 2) + 1] = 1)

typedef struct
{
	size_t	snake_size;
	WINDOW	*win;
	WINDOW	*win_score;
	int	coord_x;
	int	coord_y;
	int	dir_x;
	int	dir_y;
	size_t	score;
	size_t	map[WIDTH][HEIGHT];
	clock_t clk_start;
} snake_t;

int	my_snake(shell_t *shell, int argc, char **argv);

int	mode_ioctl(int i);
bool	speed_snake(snake_t *game);
void	set_color(WINDOW *win, int color);
bool	check_error_color(void);
size_t	game_loop(snake_t *game);
bool	quit_game(snake_t *game, char key[4]);
