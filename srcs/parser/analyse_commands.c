/*
** EPITECH PROJECT, 2018
** analyse_command.c
** File description:
** Arthur
*/

#include "lemin.h"

static int command(char *line)
{
	if (my_strcmp(line, "##start\n") == 0)
		return (1);
	else if (my_strcmp(line, "##end\n") == 0)
		return (2);
	else
		return (0);
}

int analyse_command(char *line, int *type_next_room)
{
	if (line[0] == '#') {
		if (line[1] == '#') {
			*type_next_room = command(line);
		}
		return (1);
	}
	return (0);
}
