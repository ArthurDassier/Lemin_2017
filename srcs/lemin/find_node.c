/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** find_node
*/
#include "lemin.h"

// Returns the node given as parameters
t_adj_node	*find_node(t_graph *graph, int to_find)
{
	t_adj_node	*node;

	for (int i = 0; i < graph->vertices; ++i) {
		node = graph->array[i].head;
		while (node) {
			if (node->dest == to_find)
				return (node);
			node = node->next;
		}
	}
	return (NULL);
}