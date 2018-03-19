/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** print_graph
*/
#include "graph.h"

// A utility function to print the adjacenncy list representation of graph
void print_graph(graph_t *graph)
{
	adj_node_t	*crawl;

	for (int i = 0; i < graph->vertices; ++i) {
		crawl = graph->array[i].head;
		my_printf("\n Adjacency list of vertex %d\n head ", i);
		while (crawl) {
			my_printf("-> %d", crawl->dest);
			crawl = crawl->next;
		}
		my_printf("\n");
	}
}