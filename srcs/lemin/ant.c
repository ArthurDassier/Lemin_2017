/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** ant
*/
#include "lemin.h"

t_node	*check_ants(t_node *ant_list)
{
	t_node	*tmp = ant_list;
	t_ant	*ant;

	do {
		ant = (t_ant *)tmp->data;
		if (ant->moved == false)
			return (tmp);
		tmp = tmp->next;
	} while (tmp != ant_list);
	return (NULL);
}

void	update_ants(t_node *path, t_node *tmp, t_node **ant_list)
{
	t_ant *ant= (t_ant *)tmp->data;
	t_room	*room = (t_room *)ant->room->data;

	ant->moved = true;
	room->ant = false;
	ant->room = path;
	room = (t_room *)path->data;
	if (room->type == END) {
		delete_node(ant_list, ant->ant_nb);
		room->ant_total += 1;
	}
	else
		room->ant = true;
	display_moves(ant->ant_nb, room->name_room);
}