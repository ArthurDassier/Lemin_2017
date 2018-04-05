/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** display
*/

#include "lemin.h"

static void print_room(t_room *room)
{
	if (room->type == 1)
		my_printf("##start\n");
	else if (room->type == 2)
		my_printf("##end\n");
	my_printf("%s", room->name_room);
	my_printf("%d %d\n", room->x, room->y);
}

static int find_nb_of_ants(t_room *room)
{
	t_room	*tmp = room;

	while (tmp->type != 1)
		tmp = tmp->next;
	return (tmp->ant);
}

static void print_tunnels(t_tunnels *tunnels)
{
	t_tunnels	*tmp = tunnels;
	int		*data = NULL;

	do {
		data = (int *)tmp->data;
		my_printf("%d-%d\n", data[0], data[1]);
		tmp = tmp->next;
	} while (tmp != tunnels);
}

void diaplay_infos(s_infos *infos, char **tab)
{
	t_room	*head = infos->rooms;
	t_room	*room = NULL;

	room = (t_room *)infos->rooms;
	my_printf("#number_of_ants\n");
	my_printf("%d\n", find_nb_of_ants(infos->rooms));
	my_printf("#rooms\n");
	do {
		room = (t_room *)infos->data;
		print_room(room);
	} while (infos->rooms != head);
	my_printf("#tunnels");
	print_tunnels(infos->tunnels);
	my_printf("#moves\n");
}