/*
** EPITECH PROJECT, 2017
** power4
** File description:
** power4.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "game.h"

static size_t return_pos(char tab[7][6], ssize_t score[7])
{
	size_t pos = 0;

	for (size_t i = 1; i < 7; i++) {
		bool er = tab[pos][0] != '.';

		if (er || (tab[i][0] == '.' && score[i] > score[pos]))
			pos = i;
	}
	return (pos);
}

static void drop(char tab[7][6])
{
	bool tmp = false;

	for (size_t j = 6 - 1; j > 0; j--)
		for (size_t i = 0; i < 7; i++) {
			bool cond1 = (tab[i][j - 1] != '.');
			bool cond2 = (tab[i][j] == '.');

			cond1 && cond2 ? tmp = true : 0;
			cond1 && cond2 ? tab[i][j] = tab[i][j - 1] : 0;
			cond1 && cond2 ? tab[i][j - 1] = '.' : 0;
		}
	if (tmp)
		drop(tab);
}

static ssize_t simule(char tab[7][6])
{
	char win = 0;
	char c = 'o';

	while (!win) {
		size_t pos = rand() % 7;

		while (tab[pos][0] != '.')
			pos = rand() % 7;
		tab[pos][0] = c;
		c = (c == 'o' ? 'x' : 'o');
		drop(tab);
		win = test_win(tab);
	}
	if (win == ' ')
		return (0);
	return (win == 'x' ? 1 : -1);
}

size_t ia(char tab[7][6])
{
	ssize_t score[7] = {0};

	for (size_t n = 0; n < 100000; n++) {
		char tab2[7][6];
		size_t pos = rand() % 7;

		for (size_t i = 0; i < 7; i++)
			for (size_t j = 0; j < 6; j++)
				tab2[i][j] = tab[i][j];
		while (tab2[pos][0] != '.')
			pos = rand() % 7;
		tab2[pos][0] = 'x';
		drop(tab2);
		score[pos] += simule(tab2);
	}
	return (return_pos(tab, score));
}
