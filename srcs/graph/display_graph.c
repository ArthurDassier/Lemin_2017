/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** display_graph
*/
#include "lemin.h"

void	display_graph(void *data)
{
	t_room *room = (t_room *)data;

	my_printf("nb_room = %d\n", room->nb_room);
}