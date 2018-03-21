/*
** EPITECH PROJECT, 2018
** recup_anthill.c
** File description:
** Arthur
*/

#include "lemin.h"
#include "define.h"
#include <stdio.h>

static t_room *fill_rooms(char **tab, int *type, int nb_ants)
{
	t_room	*rooms = malloc(sizeof(t_room));

	if (rooms == NULL)
		return (NULL);
	if (*type == 1)
		rooms->ant = nb_ants;
	else
		rooms->ant = 0;
	if (check_params(tab) == FAILURE)
		return (NULL);
	rooms->name_room = tab[0];
	rooms->x = my_getnbr(tab[1]);
	rooms->y = my_getnbr(tab[2]);
	rooms->type = *type;
	*type = 0;
	return (rooms);
}

static int init_anthill(char *line, t_infos *infos, int i, int *type)
{
	static int	nb_ants = 0;

	if (nb_ants == 0) {
		nb_ants = my_getnbr(line);
		if (nb_ants <= 0)
			return (FAILURE);
		return (SUCCESS);
	}
	infos->rooms[i] = fill_rooms(my_str_to_wordtab_delim(line, " "),
	type, nb_ants);
	if (infos->rooms[i] == NULL)
		return (FAILURE);
	infos->rooms[i + 1] = NULL;
	return (SUCCESS);
}

static int tunnel_or_room(char *ln, t_infos *inf, int *next_room, int *j)
{
	static int	i = -1;

	if (found_tunnels(ln) == 1) {
		if (fuel_tnl(my_str_to_wordtab_delim(ln, "-"), inf, *j) == 84)
			return (FAILURE);
		++*j;
	} else if (init_anthill(ln, inf, i, next_room) == FAILURE)
		return (FAILURE);
	++i;
	return (SUCCESS);
}

static int load_file(char *line, t_infos *inf, int *next_room, int *j)
{

	if (analyse_command(line, next_room) == 0)
		if (tunnel_or_room(line, inf, next_room, j) == FAILURE)
			return (FAILURE);
	return (SUCCESS);
}

int recup_anthill(t_infos *infos, int nb_rm)
{
	FILE	*fd = stdin;
	char	*line = NULL;
	size_t	len = 0;
	int	read = 0;
	int	type_next_room = 0;
	int	j = 0;

	infos->rooms = malloc(sizeof(t_room) * nb_rm);
	infos->tunnels->tab_tunnels = malloc(sizeof(int *) * nb_rm);
	if (infos->rooms == NULL || infos->tunnels->tab_tunnels == NULL)
		return (FAILURE);
	while ((read = getline(&line, &len, fd)) != -1)
		if (load_file(line, infos, &type_next_room, &j) == FAILURE)
			return (FAILURE);
	if (fuel_room_name(infos, nb_rm) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
