/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** add_edge
*/
#include "graph.h"

// Adds an edge to an undirected graph
void add_edge(graph_t *graph, int src, int dest)
{
	adj_node_t* new_node = add_node_list(dest);

	new_node->next = graph->array[src].head;
	graph->array[src].head = new_node;
	new_node = add_node_list(src);
	new_node->next = graph->array[dest].head;
	graph->array[dest].head = new_node;
}