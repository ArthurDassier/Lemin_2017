/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** display_graph
*/
#include "lemin.h"

void	display_graph(void *data)
{
	t_lemin *lemin = (t_lemin *)data;

	my_printf("nb_room = %d\n", lemin->nb_room);
}