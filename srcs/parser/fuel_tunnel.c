/*
** EPITECH PROJECT, 2018
** fuel_tunnel.c
** File description:
** Arthur
*/

#include "lemin.h"
#include "define.h"
#include <stdio.h>

static void place_strategic_room(t_infos *infos, int type, int i)
{
	if (type == 0)
		return;
	if (type == START)
		infos->index_start = i;
	else
		infos->index_end = i;
}

//place index for each room name
char **fuel_room_name(t_infos *infos)
{
	int	i = 0;
	char	**tab;
	t_node	*tmp_node = infos->rooms;
	t_room	*tmp_room = NULL;

	if (tmp_node == NULL)
		return (NULL);
	for (i = 0; i == 0 || tmp_node != infos->rooms; ++i)
		tmp_node = tmp_node->next;
	tab = malloc(sizeof(char *) * (i + 1));
	tmp_node = infos->rooms;
	for (i = 0; i == 0 || tmp_node != infos->rooms; ++i) {
		tmp_room = (t_room *)tmp_node->data;
		tab[i] = tmp_room->name_room;
		place_strategic_room(infos, tmp_room->type, i);
		tmp_node = tmp_node->next;
	}
	tab[i] = NULL;
	if (check_for_double_names(tab) == FAILURE)
		return (NULL);
	return (tab);
}

//protect against double declaration of tunnels
static void check_existing_tunnels(t_node **tunnels, t_node **dplay,
int *tab, int *tmp_tunnel)
{
	t_node	*tmp_node = (*tunnels);

	if (tab[0] == tab[1]) {
		insert_end(dplay, tab);
		return;
	}
	if (*tunnels == NULL) {
		insert_end(tunnels, tab);
		insert_end(dplay, tab);
		return;
	}
	insert_end(dplay, tab);
	do {
		tmp_tunnel = (int *)tmp_node->data;
		if ((tab[0] == tmp_tunnel[0] && tab[1] == tmp_tunnel[1])
		|| (tab[0] == tmp_tunnel[1] && tab[1] == tmp_tunnel[0]))
			return;
		tmp_node = tmp_node->next;
	} while (tmp_node != (*tunnels));
	insert_end(tunnels, tab);
}

//check if tunnels connect existing rooms
static int look_for_index(char **line, t_infos *infos,
int room, t_room *tmp_room)
{
	t_node	*tmp_node = infos->rooms;
	int	*tab = malloc(sizeof(int) * 3);

	for (int i = 0; i == 0 || tmp_node != infos->rooms; ++i) {
		tmp_room = (t_room *)tmp_node->data;
		if (my_strcmp(tmp_room->name_room, line[0]) == 0) {
			tab[0] = i;
			++room;
		}
		if (my_strcmp(tmp_room->name_room, line[1]) == 0) {
			tab[1] = i;
			++room;
		}
		tmp_node = tmp_node->next;
	}
	if (room != 2)
		return (FAILURE);
	tab[2] = -1;
	check_existing_tunnels(&infos->tunnels, &infos->t_display, tab, NULL);
	return (SUCCESS);
}

//get tunnel infos
int fuel_tnl(char **line, t_infos *infos)
{
	static int	first = 0;

	if (!line[0] || !line[1] || line[2] || infos->rooms == NULL ||
	end_n_start(infos->rooms) == FAILURE)
		return (FAILURE);
	line[1][found_l_problem(line[1])] = '\0';
	if (look_for_index(line, infos, 0, NULL) == FAILURE) {
		return (FAILURE);
	}
	if (first == 0) {
		my_putstr("#tunnels\n");
		first = 1;
	}
	my_printf("%s-%s\n", line[0], line[1]);
	return (SUCCESS);
}
