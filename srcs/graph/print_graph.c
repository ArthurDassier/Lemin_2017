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
	t_lemin	*lemin = (t_lemin *)data;

	my_printf("-> %d \n", lemin->nb_room);
}

// A utility function to print the adjacenncy list representation of graph
void print_graph(t_node *node)
{
	t_node		*tmp = node;
	t_lemin		*lemin;

	do {
		lemin = (t_lemin *)tmp->data;
		my_printf("Room -> %d\n", lemin->nb_room);
		for (int i = 0; tmp->graph && tmp->graph[i] != NULL; ++i) {
			lemin = (t_lemin *)tmp->graph[i]->data;
			my_printf("edge -> %d, ", lemin->nb_room);
		}
		my_printf("\n");
		tmp = tmp->next;
	} while (tmp != node);
}