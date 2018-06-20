/*
** EPITECH PROJECT, 2017
** my_power4
** File description:
** my_power4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "game.h"
#include "error.h"

static void ia_play(char tab[7][6], size_t *pos, char *c)
{
	static size_t pos_ia = 7;

	if (pos_ia == 7)
		pos_ia = ia(tab);
	if (*pos == pos_ia) {
		tab[*pos][0] = *c;
		*c = (*c == 'o' ? 'x' : 'o');
		pos_ia = 7;
		return;
	}
	*pos < pos_ia ? *pos += 1 : 0;
	*pos > pos_ia ? *pos -= 1 : 0;
}

static void play(char tab[7][6], size_t *pos, char *c)
{
	char key;

	if (*c == 'o') {
		scanf("%c", &key);
		if (key == 'q')
			tab[3][2] = 'Q';
		if (key == 'd' && tab[*pos][0] == '.') {
			tab[*pos][0] = *c;
			*c = (*c == 'o' ? 'x' : 'o');
		}
		key == 'l' && *pos > 0 ? *pos -= 1 : 0;
		key == 'r' && *pos < 6 ? *pos += 1 : 0;
	}
	else
		ia_play(tab, pos, c);
}

static bool drop(char tab[7][6])
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
	return (tmp);
}

static void aff(char tab[7][6], size_t pos, char c)
{
	printf("\e[1;1H\e[2J");
	c == 'o' ? printf("\033[%sm", "31") : 0;
	c == 'x' ? printf("\033[%sm", "33") : 0;
	printf("\033[%sm", "1");
	for (size_t i = 0; i < 7; i++)
		printf("%c", i == pos ? c : ' ');
	printf("\n");
	printf("\033[%sm", "0");
	for (size_t j = 0; j < 6; j++) {
		for (size_t i = 0; i < 7; i++) {
			tab[i][j] == 'o' ? printf("\033[%sm", "31") : 0;
			tab[i][j] == 'x' ? printf("\033[%sm", "33") : 0;
			tab[i][j] != '.' ? printf("\033[%sm", "1") : 0;
				printf("%c", tab[i][j]);
			printf("\033[%sm", "0");
		}
		printf("\n");
	}
	usleep(100000);
}

int my_power4(shell_t *shell, int argc, char **argv)
{
	char win = 0;
	char tab[7][6];
	size_t pos = 3;
	char c = 'o';

	(void)shell;
	if (argc > 1)
		return (printf(TOO_ARG, argv[0]), EXIT_FAILURE);
	for (size_t i = 0; i < 7; i++)
		for (size_t j = 0; j < 6; j++)
			tab[i][j] = '.';
	while (!win) {
		if (!drop(tab)) {
			win = test_win(tab);
			aff(tab, pos, c);
			!win ? play(tab, &pos, &c) : 0;
		} else
			aff(tab, pos, ' ');
	}
	return (win == 'o' ? EXIT_SUCCESS : EXIT_FAILURE);
}
