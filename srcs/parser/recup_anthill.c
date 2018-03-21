/*
** EPITECH PROJECT, 2018
** recup_anthill.c
** File description:
** Arthur
*/

#include "lemin.h"
#include "define.h"
#include <stdio.h>

t_room *fill_rooms(char **tab, int *type, int nb_ants)
{
	t_room	*rooms = malloc(sizeof(t_room));

	if (rooms == NULL)
		return (NULL);
	if (*type == 1)
		rooms->ant = nb_ants;
	else
		rooms->ant = 0;
	rooms->nb_room = my_getnbr(tab[0]);
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
		return (SUCCESS);
	}
	infos->rooms[i] = fill_rooms(my_str_to_wordtab_delim(line, " "),
	type, nb_ants);
	if (infos->rooms[i] == NULL)
		return (FAILURE);
	return (SUCCESS);
}

static int the_while(char *line, t_infos *inf, int *next_room, int *j)
{
	static int	i = -1;

	if (analyse_command(line, next_room) == 0) {
		if (found_tunnels(line) == 1) {
			fuel_tnl(my_str_to_wordtab_delim(line, "-"), inf, *j);
			++*j;
		} else if (init_anthill(line, inf, i, next_room) == FAILURE)
			return (FAILURE);
		++i;
	}
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
	infos->tunnels->tunnels = malloc(sizeof(int *) * 5);
	while ((read = getline(&line, &len, fd)) != -1)
		the_while(line, infos, &type_next_room, &j);
	fuel_room_name(infos, nb_rm);
	return (SUCCESS);
}
