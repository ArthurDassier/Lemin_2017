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

int handle_command(char *line)
{
	if (line[2] == 's') {
		return (1);
	} else
		return (2);
}

static int analyse_commentary(char *line)
{
	if (line[0] == '#') {
		if (line[1] == '#') {
			return (handle_command(line));
		}
		return (-1);
	}
	return (0);
}

static void init_anthill(char *line, t_tunnels *tunnels, t_room **rooms, int *i)
{
	static int	type = 0;
	static int	nb_ants = -1;

	printf(">>%d\n", type);
	(void) tunnels;
	if ((type = analyse_commentary(line)) != 0) {
		*i -= 1;
		return;
	}
	if (nb_ants == -1) {
		nb_ants = my_getnbr(line);
		*i -= 1;
		return;
	}
	rooms[*i] = fill_rooms(my_str_to_wordtab_delim(line, " "), &type, nb_ants);
}

t_room **recup_anthill(t_tunnels *tunnels, int nb_rm)
{
	FILE	*fd = stdin;
	int	i = 0;
	char	*line = NULL;
	size_t	len = 0;
	int	read = 0;
	int	type_next_room = 0;
	int	i = -1;
	int	j = 0;
	infos->rooms = malloc(sizeof(t_room) * nb_rm);
	infos->tunnels->tunnels = malloc(sizeof(int *) * 5);

	(void) tunnels;
	while ((read = getline(&line, &len, fd)) != -1) {
		if (analyse_command(line, &type_next_room) == 0) {
			if (found_tunnels(line) == 1) {
				fuel_tunnel(my_str_to_wordtab_delim(line, "-"), infos, j);
				++j;
			} else if (init_anthill(line, infos, i, &type_next_room) == FAILURE)
				return (FAILURE);
			++i;
		}
	}
	fuel_room_name(infos, nb_rm);
	return (SUCCESS);
}
