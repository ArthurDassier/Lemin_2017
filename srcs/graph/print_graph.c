/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** print_graph
*/
#include "lemin.h"

// A utility function to print the adjacenncy list representation of graph
void print_graph(t_graph *graph)
{
	t_adj_node	*crawl;
	t_room		*tmp = NULL;

	for (int i = 0; i < graph->vertices; ++i) {
		crawl = graph->array[i].head;
		my_printf("\n Adjacency list of vertex %d\n head ", i);
		while (crawl) {
			my_printf("-> %d", crawl->dest);
			crawl = crawl->next;
		}
		tmp = (t_room *)graph->array[i].head->data;
		my_printf("\n ant	 ==> %d\n", tmp->ant);
		my_printf(" nb_room ==> %d\n", tmp->nb_room);
		my_printf(" type	 ==> %d\n", tmp->type);
		my_printf(" pos_x	 ==> %d\n", tmp->x);
		my_printf(" pos_y	 ==> %d\n", tmp->y);
	}
}