/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** get_total
*/
#include "lemin.h"

int	get_total_end(t_node *node)
{
	t_room *room = (t_room *)node->data;

	return (room->ant_total);
}

int get_total(t_node *node)
{
	t_room *room = (t_room *)node->data;

	return (room->ant_total);
}