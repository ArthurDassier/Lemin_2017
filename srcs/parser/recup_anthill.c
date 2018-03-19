/*
** EPITECH PROJECT, 2018
** recup_anthill.c
** File description:
** Arthur
*/

#include "lemin.h"
#include "define.h"
#include <stdio.h>

t_room *fill_rooms(char **tab, int *type)
{
	t_room	rooms = malloc(sizeof(t_room));

	rooms.ant = 0;
	rooms.nb_room = my_getnbr(tab[0]);
	rooms.x = my_getnbr(tab[1]);
	rooms.y = my_getnbr(tab[2]);
	rooms.type = *type;
	*type = 0;
}

int handle_command(char *line, t_tunnels *tunnels, t_room *rooms)
{
	if (line[3] == 's') {
		return (1);
	} else
		return (2);
}

static int analyse_commentary(char *line, t_tunnels *tunnels)
{
	if (line[0] == '#') {
		if (line[1] == "#") {
			return (handle_command(line, tunnels));
		}
		return (-1);
	}
	return (0);
}

static void init_anthill(char *line, t_tunnels *tunnels, t_room **rooms, int *i)
{
	static int	type = 0;

	if ((type = analyse_commentary(line, tunnels)) == -1) {
		*i -= 1;
		return;
	}
	rooms[*i] = fill_rooms(my_str_to_word_array(line, " "), &type);
}

t_room **recup_anthill(t_tunnels *tunnels, int nb_rm)
{
	FILE	*fd = stdin;
	int	i = 0;
	char	*line = NULL;
	size_t	len = 0;
	int	read = 0;
	int	nb_ant = 0;
	t_room **rooms = malloc(sizeof(t_room) * nb_rm);

	while ((read = getline(&line, &len, fd)) != -1) {
		init_anthill(line, tunnels, rooms, &i);
		++i;
	}
	return (rooms);
}
