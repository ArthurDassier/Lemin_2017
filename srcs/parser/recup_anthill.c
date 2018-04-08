/*
** EPITECH PROJECT, 2018
** recup_anthill.c
** File description:
** Arthur
*/

#include "lemin.h"
#include "define.h"
#include <stdio.h>

//fill each room infos
static int fill_rooms(t_node **rm, char **tab, int *type, int nb_ants)
{
	t_room	*rooms = malloc(sizeof(t_room));

	if (rooms == NULL)
		return (FAILURE);
	if (*type == START)
		rooms->ant_total = nb_ants;
	else
		rooms->ant_total = 0;
	if (check_params(tab) == FAILURE)
		return (FAILURE);
	rooms->name_room = tab[0];
	rooms->x = my_getnbr(tab[1]);
	rooms->y = my_getnbr(tab[2]);
	if (rooms->x < 0 || rooms->y < 0)
		return (FAILURE);
	rooms->type = *type;
	*type = 0;
	insert_end(rm, rooms);
	return (SUCCESS);
}

//Init the number of ants and send room infos
static int init_anthill(char *line, t_infos *infos, int *type)
{
	static int	nb_ants = 0;

	if (nb_ants == 0) {
		nb_ants = my_getnbr(line);
		if (nb_ants <= 0)
			return (FAILURE);
		return (SUCCESS);
	}
	if (fill_rooms(&infos->rooms, my_str_to_wordtab_delim(line, " "),
	type, nb_ants) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int tunnel_or_room(char *ln, t_infos *inf, int *next_room)
{
	static int	i = -1;

	if (found_tunnels(ln) == 1) {
		if (fuel_tnl(my_str_to_wordtab_delim(ln, "-"), inf) == 84)
			return (FAILURE);
	} else if (init_anthill(ln, inf, next_room) == FAILURE)
		return (FAILURE);
	++i;
	return (SUCCESS);
}

//check for commands
static int load_file(char *line, t_infos *inf, int *next_room)
{
	if (analyse_command(line, next_room) == 0)
		if (tunnel_or_room(line, inf, next_room) == FAILURE)
			return (FAILURE);
	return (SUCCESS);
}

//Initialisation of infos and index
char **recup_anthill(t_infos **infos, char **index)
{
	FILE	*fd = stdin;
	char	*line = NULL;
	size_t	len = 0;
	int	read = 0;
	int	type_next_room = 0;

	*infos = malloc(sizeof(t_infos));
	if (*infos == NULL)
		return (NULL);
	init_inf(infos);
	while ((read = getline(&line, &len, fd)) != -1)
		if (load_file(line, *infos, &type_next_room) == FAILURE)
			return (NULL);
	if (look_for_coordinates((*infos)->rooms) == FAILURE)
		return (NULL);
	if (end_n_start((*infos)->rooms) == FAILURE)
		return (NULL);
	index = fuel_room_name(*infos);
	return (index);
}
