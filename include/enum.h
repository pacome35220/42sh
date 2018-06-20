/*
** EPITECH PROJECT, 2018
** enum
** File description:
** enum
*/

#pragma once

enum id_delim
{
	ID_TXT		=	-1,
	ID_SPACE	=	0,
	ID_TAB		=	1,
	ID_SEMICOLON	=	2,
	ID_DLREDIR	=	3,
	ID_LREDIR	=	4,
	ID_DRREDIR	=	5,
	ID_RREDIR	=	6,
	ID_AND		=	7,
	ID_OR		=	8,
	ID_PIPE		=	9,
	ID_SIMPLE	=	10,
	ID_DOUBLE	=	11
};

enum type_delim
{
	TD_NORMAL,
	TD_DELIM,
	TD_GET,
	TD_SEPARATOR,
};
