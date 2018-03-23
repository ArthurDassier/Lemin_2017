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

int fuel_tnl(char **line, t_infos *infos, int j)
{
	infos->tunnels->tab_tunnels[j] = malloc(sizeof(int) * 2);
	if (infos->tunnels->tab_tunnels[j] == NULL)
		return (FAILURE);
	if (!line[0] || !line[1])
		return (FAILURE);
	infos->tunnels->tab_tunnels[j][0] = my_getnbr(line[0]);
	infos->tunnels->tab_tunnels[j][1] = my_getnbr(line[1]);
	return (SUCCESS);
}
