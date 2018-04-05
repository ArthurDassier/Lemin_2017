/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** error_on_graph
*/

#include "lemin.h"

bool is_a_path(t_node *node)
{
	t_node	*tmp = node;
	t_room	*room = NULL;

	room = (t_room *)tmp->data;
	while (room->type != 1) {
		room = (t_room *)tmp->data;
		tmp = tmp->next;
	}
	for (int i = 0; tmp->graph && tmp->graph[i] != NULL; ++i) {
		room = (t_room *)tmp->graph[i]->data;
		if (room->type == 2)
			return (true);
	}
	return (false);
}