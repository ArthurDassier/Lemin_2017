/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** print_graph
*/
#include "lemin.h"

// Prints the list
void	print_list(void *data)
{
	t_room	*room = (t_room *)data;

	my_printf("-> %d \n", room->nb_room);
}

// A utility function to print the adjacenncy list representation of graph
void print_graph(t_node *node)
{
	t_node		*tmp = node;
	t_room		*room;

	do {
		room = (t_room *)tmp->data;
		my_printf("Room -> %d\n", room->nb_room);
		for (int i = 0; tmp->graph && tmp->graph[i] != NULL; ++i) {
			room = (t_room *)tmp->graph[i]->data;
			my_printf("::edge -> %d, ", room->nb_room);
		}
		my_printf("\n");
		tmp = tmp->next;
	} while (tmp != node);
}