/*
** EPITECH PROJECT, 2018
** error_coordinates.c
** File description:
** Arthur
*/

#include "lemin.h"

int look_for_coordinates_part2(t_node *tmp_node, t_node *tmp_node2)
{
	t_room	*room = NULL;
	t_room	*room_two = NULL;

	for (; tmp_node2 != tmp_node; tmp_node2 = tmp_node2->next) {
		room = (t_room*)tmp_node->data;
		room_two = (t_room*)tmp_node2->data;
		if (room->x == room_two->x && room->y == room_two->y)
			return (FAILURE);
	}
	return (SUCCESS);
}

int look_for_coordinates(t_node *rooms)
{
	t_node	*tmp_node = rooms;
	t_node	*tmp_node2 = NULL;

	for (int i = 0; i == 0 || tmp_node != rooms;
	tmp_node = tmp_node->next) {
		tmp_node2 = tmp_node->next;
		if (look_for_coordinates_part2(tmp_node, tmp_node2) == 84) {
			my_print_err("ERROR : Double"
			" coordinates declaration\n");
			return (FAILURE);
		}
		++i;
	}
	return (SUCCESS);
}
