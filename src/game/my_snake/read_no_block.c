/*
** EPITECH PROJECT, 2018
** block
** File description:
** block
*/

#include <sys/ioctl.h>
#include <termios.h>
#include "game.h"

int mode_ioctl(int i)
{
	static struct termios oldt;
	struct termios newt;

	if (i == 1) {
		ioctl(0, TCGETS, &oldt);
		ioctl(0, TCGETS, &newt);
		newt.c_lflag &= ~ICANON;
		newt.c_lflag &= ~ECHO;
		newt.c_cc[VMIN] = 0;
		ioctl(0, TCSETS, &newt);
	}
	if (i == 0)
		ioctl(0, TCSETS, &oldt);
	return (0);
}
