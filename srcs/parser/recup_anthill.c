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

int command(char *line)
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

static int init_anthill(char *line, t_infos *infos, int i, int *type)
{
	static int	nb_ants = 0;

	if (nb_ants == 0) {
		nb_ants = my_getnbr(line);
		return (SUCCESS);
	}
	infos->rooms[i] = fill_rooms(my_str_to_wordtab_delim(line, " "), type, nb_ants);
	if (infos->rooms[i] == NULL)
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
	int	i = -1;
	int	j = 0;
	infos->rooms = malloc(sizeof(t_room) * nb_rm);

	while ((read = getline(&line, &len, fd)) != -1) {
		if (analyse_command(line, &type_next_room) == 0) {
			if (found_tunnels(line) == 1) {
				fuel_tunnel(line);
				++j;
			} else if (init_anthill(line, infos, i, &type_next_room) == FAILURE)
				return (FAILURE);
			++i;
		}
	}
	return (SUCCESS);
}
