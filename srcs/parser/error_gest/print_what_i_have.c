/*
** EPITECH PROJECT, 2018
** print.c
** File description:
** Arthur
*/

#include "lemin.h"

static void print_tls(t_node *tunnels)
{
	t_node		*tmp = tunnels;
	int		*data = NULL;

	do {
		data = (int *)tmp->data;
		my_printf("%s-%s\n", data[0], data[1]);
		tmp = tmp->next;
	} while (tmp != tunnels);
}

int print_err_rooms(int nb_ants, t_node *rooms, t_node *t_display)
{
	t_node	*head = rooms;
	t_room	*room = NULL;

	if (nb_ants <= 0)
		return (FAILURE);
	my_printf("#number_of_ants\n%d\n", nb_ants);
	if (rooms == NULL)
		return (0);
	my_printf("#rooms\n");
	do {
		room = (t_room *)rooms->data;
		print_room(room);
		rooms = rooms->next;
	} while (rooms != head);
	if (t_display != NULL) {
		my_printf("#tunnels\n");
		print_tls(t_display);
	}
	return (SUCCESS);
}
