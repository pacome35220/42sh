/*
** EPITECH PROJECT, 2018
** spd
** File description:
** spd
*/

#include <time.h>
#include "game.h"

const size_t temp = 500000;
const size_t max = 100;

static void cond(snake_t *game, size_t x, size_t y)
{
	if (game->map[x][y] == 2)
		game->map[x][y] = 0;
	if (game->map[x][y] > 2)
		game->map[x][y] = game->map[x][y] - 1;
}

static void move_snake(snake_t *game)
{
	for (size_t i = 0; i < WIDTH; i++)
		for (size_t j = 0; j < HEIGHT; j++)
			cond(game, i, j);
}

static void eat_item(snake_t *game)
{
	if (game->map[game->coord_x][game->coord_y] == 1) {
		PUT_ITEM(*game);
		game->snake_size++;
		game->score++;
	}
}

bool speed_snake(snake_t *game)
{
	size_t size = (game->snake_size > max ? game->snake_size : max);

	if ((size_t) clock() > game->clk_start + temp - size * 2000) {
		game->coord_x += game->dir_x;
		game->coord_y += game->dir_y;
		game->clk_start = clock();
		eat_item(game);
		move_snake(game);
		if (game->map[game->coord_x][game->coord_y] >= 2) {
			delwin(game->win);
			delwin(game->win_score);
			mode_ioctl(0);
			return (false);
		}
		game->map[game->coord_x][game->coord_y] = game->snake_size + 1;
	}
	return (true);
}
