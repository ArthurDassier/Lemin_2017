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
	t_lemin	*lemin;

	for (int i = 0; i < vertices; ++i) {
		lemin = malloc(sizeof(*lemin));
		if (lemin == NULL)
			return (NULL);
		lemin->nb_room = i + 1;
		insert_end(node, lemin);
	}
}