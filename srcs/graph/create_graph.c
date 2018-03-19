/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** create_graph
*/
#include "graph.h"

// A utility function that creates a graph of V vertices
graph_t	*create_graph(int vertices)
{
	graph_t	*graph = (graph_t *) malloc(sizeof(graph_t));

	if (graph == NULL)
		return (NULL);
	graph->vertices = vertices;
	graph->array = (adj_list_t *) malloc(vertices * sizeof(adj_list_t));
	int i;
	for (i = 0; i < vertices; ++i)
	graph->array[i].head = NULL;

	return (graph);
}