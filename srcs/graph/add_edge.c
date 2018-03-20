/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** add_edge
*/
#include "graph.h"

//Adds an edge to an undirected graph
void add_edge(t_graph *graph, int src, int dest)
{
	t_adj_node *new_node = add_node_list(dest);

	new_node->prev = graph->array[src].prev;
	new_node->next = graph->array[src].head;
	graph->array[src].head = new_node;
	new_node = add_node_list(src);
	new_node->prev = graph->array[dest].prev;
	new_node->next = graph->array[dest].head;
	graph->array[dest].head = new_node;
}