/*
** EPITECH PROJECT, 2018
** snake
** File description:
** snake
*/

#include <stdlib.h>
#include "game.h"

static bool init_win(snake_t *game)
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	game->win = newwin(WIDTH, HEIGHT, (LINES / 2) - WIDTH / 2, COLS / 2);
	game->win_score = newwin(10, 20, 0, 0);
	if (!check_error_color())
		return (false);
	box(game->win, 0, 0);
	return (true);
}

static snake_t game_create(void)
{
	snake_t game;

	game.snake_size = 3;
	for (size_t i = 0; i < WIDTH; i++)
		for (size_t j = 0; j < HEIGHT; j++)
			game.map[i][j] = 0;
	PUT_ITEM(game);
	PUT_ITEM(game);
	PUT_ITEM(game);
	game.coord_x = WIDTH / 2;
	game.coord_y = HEIGHT / 2;
	game.dir_x = 1;
	game.dir_y = 0;
	game.score = 0;
	game.clk_start = -1;
	return (game);
}

int my_snake(shell_t *shell, int argc, char **argv)
{
	(void) shell, (void) argc, (void) argv;
	snake_t game = game_create();

	if (!init_win(&game))
		return (84);
	mode_ioctl(1);
	return (game_loop(&game));
}
