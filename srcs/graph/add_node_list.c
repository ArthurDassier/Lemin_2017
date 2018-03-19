/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** add_node_list
*/
#include "graph.h"

// A utility function to create a new adjacency list node
struct adj_node_t*	add_node_list(int dest)
{
	adj_node_t *new_node =
	(adj_node_t*) malloc(sizeof(adj_node_t));

	if (new_node == NULL)
		return (NULL);
	new_node->dest = dest;
	new_node->next = NULL;
	return (new_node);
}