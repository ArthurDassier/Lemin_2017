/*
** EPITECH PROJECT, 2018
** fuel_tunnel.c
** File description:
** Arthur
*/

#include "lemin.h"
#include "define.h"
#include <stdio.h>

int fuel_room_name(t_infos *infos, int nb_rm)
{
	int	i = 0;

	infos->tunnels->names = malloc(sizeof(char *) * (nb_rm + 1));
	if (infos->tunnels->names == NULL)
		return (FAILURE);
	while (i != nb_rm) {
		infos->tunnels->names[i] = infos->rooms[i]->name_room;
		++i;
	}
	infos->tunnels->names[i] = NULL;
	if (check_for_double_names(infos->tunnels->names) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

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

static int look_for_index(char **line, t_infos *infos, int j)
{
	int	i = 0;
	int	room = 0;

	line[1][my_strlen(line[1]) - 1] = '\0';
	while (infos->rooms[i]) {
		if (my_strcmp(infos->rooms[i]->name_room, line[0]) == 0) {
			infos->tunnels->tab_tunnels[j][0] = i;
			++room;
		}
		if (my_strcmp(infos->rooms[i]->name_room, line[1]) == 0) {
			infos->tunnels->tab_tunnels[j][1] = i;
			++room;
		}
		++i;
	}
	if (room != 2)
		return (FAILURE);
	infos->tunnels->tab_tunnels[j][2] = -1;
	return (SUCCESS);
}

int fuel_tnl(char **line, t_infos *infos, int j)
{
	infos->tunnels->tab_tunnels[j] = malloc(sizeof(int) * 3);
	if (infos->tunnels->tab_tunnels[j] == NULL)
		return (FAILURE);
	if (!line[0] || !line[1] || line[2])
		return (FAILURE);
	if (look_for_index(line, infos, j) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
