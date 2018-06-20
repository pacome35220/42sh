/*
** EPITECH PROJECT, 2018
** game_loop.c
** File description:
** game_loop.c
*/

#include <stdlib.h>
#include "game.h"

const char key_up = 'z';
const char key_down = 's';
const char key_left = 'q';
const char key_right = 'd';

static void command(snake_t *game, char key)
{
	if (!game->dir_x && key == key_right)
		game->dir_x = 1;
	if (!game->dir_x && key == key_left)
		game->dir_x = -1;
	if (key == key_up || key == key_down)
		game->dir_x = 0;
	if (!game->dir_y && key == key_up)
		game->dir_y = -1;
	if (!game->dir_y && key == key_down)
		game->dir_y = 1;
	if (key == key_right || key == key_left)
		game->dir_y = 0;
}

static void display_snake(snake_t *game)
{
	mvwprintw(game->win_score, 3, 3, "SCORE : %ld", game->score);
	for (int i = 0; i < WIDTH; i++)
		for (int j = 0; j < HEIGHT; j++) {
			set_color(game->win, 1);
			game->map[i][j] >= 2 ?
				mvwprintw(game->win, j, i, "%c", 'M') : 0;
			wattroff(game->win, COLOR_PAIR(1));
			set_color(game->win, 2);
			game->map[i][j] == 1 ?
				mvwprintw(game->win, j, i, "%c", 'O') : 0;
			wattroff(game->win, COLOR_PAIR(1));
		}
}

size_t game_loop(snake_t *game)
{
	char key = '\0';

	while (1) {
		if (quit_game(game, &key))
			return (endwin(), game->score);
		command(game, key);
		if (!speed_snake(game))
			return (endwin(), game->score);
		werase(game->win);
		box(game->win_score, 0, 0);
		box(game->win, 0, 0);
		display_snake(game);
		wrefresh(game->win);
		wrefresh(game->win_score);
	}
	return (0);
}
