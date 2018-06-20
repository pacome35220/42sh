/*
** EPITECH PROJECT, 2018
** globals_vars
** File description:
** globals_vars
*/

#include <stdlib.h>
#include "shell.h"

delim_tab_t delim_tab[] =
{
	{" ",	"",	ID_SPACE,	TD_NORMAL},
	{"\t",	"",	ID_TAB,		TD_NORMAL},
	{";",	"",	ID_SEMICOLON,	TD_SEPARATOR},
	{"<<",	"",	ID_DLREDIR,	TD_GET},
	{"<",	"",	ID_LREDIR,	TD_GET},
	{">>",	"",	ID_DRREDIR,	TD_GET},
	{">",	"",	ID_RREDIR,	TD_GET},
	{"&&",	"",	ID_AND,		TD_SEPARATOR},
	{"||",	"",	ID_OR,		TD_SEPARATOR},
	{"|",	"",	ID_PIPE,	TD_GET},
	{"'",	"'",	ID_SIMPLE,	TD_DELIM},
	{"\"",	"\"",	ID_DOUBLE,	TD_DELIM},
	{NULL,	NULL,	ID_TXT, -1}
};

char *signal_list[] =
{
	"Hangup",
	"",
	"Quit",
	"Illegal instruction",
	"Trace/BPT trap",
	"Abort",
	"BUS error",
	"Floating exception",
	"Killed",
	"User signal 1",
	"Segmentation fault",
	"User signal 2",
	"Broken pipe",
	"Alarm clock",
	"Terminated",
	"Stack limit exceeded",
	"Child process has stopped or exited, changed",
	"Continue executing, if stopped",
	"Suspended (signal)",
	"Suspended",
	"Background read from tty",
	"Background write to tty",
	"",
	"Cputime limit exceeded",
	"Filesize limit exceeded",
	"Virtual time alarm",
	"Profiling time clock",
	"",
	"Pollable event occured",
	"Pollable event occured",
	"Power failure",
	"Bad system call",
	NULL
};
