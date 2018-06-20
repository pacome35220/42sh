/*
** EPITECH PROJECT, 2018
** color
** File description:
** color
*/

#include "game.h"

// set color with font

void set_color(WINDOW *win, int color)
{
	start_color();
	init_pair(1, COLOR_RED, 1);
	init_pair(2, COLOR_GREEN, 2);
	init_pair(3, COLOR_YELLOW, 3);
	init_pair(4, COLOR_BLUE, 4);
	init_pair(5, COLOR_MAGENTA, 5);
	init_pair(6, COLOR_CYAN, 6);
	init_pair(7, COLOR_WHITE, 7);
	wattron(win, COLOR_PAIR(color));
}

// check if terminal support color

bool check_error_color(void)
{
	if (!has_colors()) {
		printf("Terminal does not support color\n");
		return (false);
	}
	return (true);
}
