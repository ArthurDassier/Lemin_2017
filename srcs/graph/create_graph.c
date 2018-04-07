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
void	create_graph(t_node **node, t_infos *infos, int vertices)
{
	t_room	*room = NULL;
	t_node	*head_room_list = infos->rooms;

	for (int i = 0; i < vertices; ++i) {
		room = malloc(sizeof(*room));
		if (room == NULL)
			return;
		room = (t_room *)infos->rooms->data;
		room->nb_room = i + 1;
		insert_end(node, room);
		infos->rooms = infos->rooms->next;
	}
	infos->rooms = head_room_list;
}