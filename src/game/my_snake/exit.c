/*
** EPITECH PROJECT, 2018
** exit
** File description:
** exit
*/

#include <unistd.h>
#include <ncurses.h>
#include "game.h"

static bool collis(snake_t *game)
{
	if (game->coord_y >= HEIGHT - 1 || game->coord_x >= WIDTH - 1
	|| game->coord_y == 0 || game->coord_x == 0)
		return (true);
	return (false);
}

// Quit game with escape key or with collision

bool quit_game(snake_t *game, char *key)
{
	if ((read(STDIN_FILENO, key, 1) == 1 && *key == '\e') || collis(game)) {
		delwin(game->win);
		delwin(game->win_score);
		mode_ioctl(0);
		return (true);
	}
	return (false);
}
