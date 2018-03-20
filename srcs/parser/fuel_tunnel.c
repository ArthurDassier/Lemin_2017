/*
** EPITECH PROJECT, 2018
** fuel_tunnel.c
** File description:
** Arthur
*/

#include "lemin.h"
#include "define.h"
#include <stdio.h>

void fuel_room_name(t_infos *infos, int nb_rm)
{
	int	i = 0;

	infos->tunnels->names = malloc(sizeof(char *) * nb_rm);
	while (infos->rooms[i]) {
		infos->tunnels->names[i] = malloc(sizeof(char) * nb_rm);
		infos->tunnels->names[i] = my_itoa(infos->rooms[i]->nb_room);
		++i;
	}
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

void fuel_tunnel(char **line, t_infos *infos, int j)
{
	infos->tunnels->tunnels[j] = malloc(sizeof(int) * 2);
	infos->tunnels->tunnels[j][0] = my_getnbr(line[0]);
	infos->tunnels->tunnels[j][1] = my_getnbr(line[1]);
}
