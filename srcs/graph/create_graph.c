/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** create_graph
*/
#include "list.h"
#include "lemin.h"

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