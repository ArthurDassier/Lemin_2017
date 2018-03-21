/*
** EPITECH PROJECT, 2018
** analyse_command.c
** File description:
** Arthur
*/

static int command(char *line)
{
	if (line[2] == 's') {
		return (1);
	} else
		return (2);
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
