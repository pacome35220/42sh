/*
** EPITECH PROJECT, 2017
** power4
** File description:
** power4_test_win.c
*/

#include "game.h"

static char test_win2(char tab[7][6])
{
	char tmp = 0;

	for (size_t i = 0; i < 7 - (4 - 1); i++)
		for (size_t j = 0; j < 6 - (4 - 1); j++) {
			char c = (tab[i][j] != '.' ? tab[i][j] : 0);
			bool cond = tab[i + 1][j + 1] == c;

			cond = c && cond && tab[i + 2][j + 2] == c;
			cond && tab[i + 3][j + 3] == c ? tmp = c : 0;
		}
	for (size_t i = (4 - 1); i < 7; i++)
		for (size_t j = 0; j < 6 - (4 - 1); j++) {
			char c = (tab[i][j] != '.' ? tab[i][j] : 0);
			bool cond = tab[i - 1][j + 1] == c;

			cond = c && cond && tab[i - 2][j + 2] == c;
			cond && tab[i - 3][j + 3] == c ? tmp = c : 0;
		}
	return (tmp);
}

static char test_win1(char tab[7][6])
{
	char tmp = 0;

	for (size_t i = 0; i < 7 - (4 - 1); i++)
		for (size_t j = 0; j < 6; j++) {
			char c = (tab[i][j] != '.' ? tab[i][j] : 0);
			bool cond = tab[i + 1][j] == c && tab[i + 2][j] == c;

			c && cond && tab[i + 3][j] == c ? tmp = c : 0;
		}
	for (size_t i = 0; i < 7; i++)
		for (size_t j = 0; j < 6 - (4 - 1); j++) {
			char c = (tab[i][j] != '.' ? tab[i][j] : 0);
			bool cond = tab[i][j + 1] == c && tab[i][j + 2] == c;

			c && cond && tab[i][j + 3] == c ? tmp = c : 0;
		}
	return (tmp);
}

static char test_win0(char tab[7][6])
{
	char tmp = ' ';

	for (size_t i = 0; tmp == ' ' && i < 7; i++)
		for (size_t j = 0; tmp == ' ' && j < 6; j++)
			tab[i][j] == 'Q' ? tmp = 'Q' : 0;
	for (size_t i = 0; tmp == ' ' && i < 7; i++)
		for (size_t j = 0; tmp == ' ' && j < 6; j++)
			tab[i][j] == '.' ? tmp = 0 : 0;
	return (tmp);
}

char test_win(char tab[7][6])
{
	char tmp = test_win0(tab);

	if (tmp == 0)
		tmp = test_win1(tab);
	if (tmp == 0)
		tmp = test_win2(tab);
	return (tmp);
}
