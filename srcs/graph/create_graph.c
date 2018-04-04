/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** create_graph
*/
#include "list.h"
#include "lemin.h"

// A utility function that creates a graph of V vertices
void	create_graph(t_node **node, int vertices)
{
	t_room	*room;

	for (int i = 0; i < vertices; ++i) {
		room = malloc(sizeof(*room));
		if (room == NULL)
			return;
		room->nb_room = i + 1;
		insert_end(node, room);
	}
}