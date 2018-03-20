/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** create_graph
*/
#include "graph.h"

// A utility function that creates a graph of V vertices
t_graph	*create_graph(int vertices)
{
	t_graph	*graph = (t_graph *) malloc(sizeof(t_graph));

	if (graph == NULL)
		return (NULL);
	graph->vertices = vertices;
	graph->array = (t_adj_list *) malloc(vertices * sizeof(t_adj_list));
	if (graph->array == NULL)
		return (NULL);
	for (int i = 0; i < vertices; ++i)
		graph->array[i].head = NULL;
	return (graph);
}