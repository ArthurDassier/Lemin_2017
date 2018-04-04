/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** create_graph
*/
#include "list.h"
#include "lemin.h"

static void remp_rooms_info(t_room *room, t_node *room_list)
{
	t_room	*info = NULL;

	info = (t_room *)room_list->data;
	room->type = info->type;
	room->ant_total = info->ant_total;
	room->ant = false;
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
		room->nb_room = i + 1;
		remp_rooms_info(room, infos->rooms);
		infos->rooms = infos->rooms->next;
		insert_end(node, room);
	}
	infos->rooms = head_room_list;
}