/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** create_graph
*/
#include "list.h"
#include "lemin.h"

static void	init_room(t_room *room, int i)
{
	room->nb_room = i + 1;
	room->ant = false;
	if (room->nb_room == 5)
		room->type = 2;
	else if (room->nb_room == 1)
		room->type = 1;
	else
		room->type = 0;
}

// A utility function that creates a graph of V vertices
void	create_graph(t_node **node, int vertices)
{
	t_room	*room;

	for (int i = 0; i < vertices; ++i) {
		room = malloc(sizeof(*room));
		if (room == NULL)
			return;
		init_room(room, i);
		insert_end(node, room);
	}
}