/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** display
*/

#include "lemin.h"

// display infos of a room (name, x, y) with ##start and ##end
void print_room(t_room *room)
{
	if (room->type == 1)
		my_printf("##start\n");
	else if (room->type == 2)
		my_printf("##end\n");
	my_printf("%s ", room->name_room);
	my_printf("%d %d\n", room->x, room->y);
}

// find room start and display the nb of ants
static int find_nb_of_ants(t_node *room)
{
	t_node	*tmp = room;
	t_room	*info_room = (t_room *)tmp->data;

	while (info_room->type != 1) {
		tmp = tmp->next;
		info_room = (t_room *)tmp->data;
	}
	return (info_room->ant_total);
}

// print tunnels (bond)
static void print_tunnels(t_node *tunnels, char **tab)
{
	t_node		*tmp = tunnels;
	int		*data = NULL;

	do {
		data = (int *)tmp->data;
		my_printf("%s-%s\n", tab[data[0]], tab[data[1]]);
		tmp = tmp->next;
	} while (tmp != tunnels);
}

// main function to diaplay NB_ANT / ROOMS / TUNNELS
void display_infos(t_infos *infos, char **tab)
{
	t_node	*head = infos->rooms;
	t_room	*room = NULL;

	my_printf("#number_of_ants\n");
	my_printf("%d\n", find_nb_of_ants(infos->rooms));
	my_printf("#rooms\n");
	do {
		room = (t_room *)infos->rooms->data;
		print_room(room);
		infos->rooms = infos->rooms->next;
	} while (infos->rooms != head);
	my_printf("#tunnels\n");
	print_tunnels(infos->t_display, tab);
	my_printf("#moves\n");
}
