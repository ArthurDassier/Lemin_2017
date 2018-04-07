/*
** EPITECH PROJECT, 2018
** analyse_command.c
** File description:
** Arthur
*/

#include "lemin.h"

//check if the line is a tunnel
int found_tunnels(char *line)
{
	int	i = 0;

	while (line[i] != '\0') {
		if (line[i] == '-')
			return (1);
		++i;
	}
	return (0);
}

static int command(char *line)
{
	if (my_strcmp(line, "##start\n") == 0)
		return (START);
	else if (my_strcmp(line, "##end\n") == 0)
		return (END);
	else
		return (NORMAL);
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
