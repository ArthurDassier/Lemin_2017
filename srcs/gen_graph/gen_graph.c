/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** gen_graph
*/

#include "lemin.h"

static int find_nb_vertices(t_node *room)
{
	t_node	*tmp_node = room;
	t_room	*tmp_room = NULL;
	int	vertices = 0;

	room = room->prev;
	tmp_room = (t_room *)room->data;
	vertices = tmp_room->nb_room;
	room = tmp_node;
	return (vertices);
}

static void remp_rooms_info(t_node **graph, t_node *room_list)
{
	t_room		*graph_room = NULL;
	t_room		*room_index = NULL;
	t_node		*tmp_node = room_list;
	int		i = 0;

	do {
		room_index = (t_room *)room_list->data;
		i = room_index->nb_room;
		tmp_node = graph[i];
		graph[i]->data = malloc(sizeof(t_room));
		graph_room = (t_room *)tmp_node->data;
		graph_room->ant = false;
		graph_room->type = room_index->type;
		graph_room->nb_room = room_index->nb_room;
		room_list = room_list->next;
	} while (room_list != tmp_node);
}

static void gen_edges(t_node *graphi, t_node *tunnels)
{
	t_node	*tmp_tun = tunnels;
	int	*tmp_int = NULL;

	tunnels = tunnels->next;
	while (tunnels != tmp_tun) {
		tmp_int = (int *)tunnels->data;
		add_edge(graphi, tmp_int[0], tmp_int[1]);
		tunnels = tunnels->next;
	}
}

t_node	*gen_graph(t_infos *infos)
{
	t_node		*graphi = malloc(sizeof(t_node));

	graphi->graph = malloc(sizeof(t_node *) * find_nb_vertices(infos->rooms));
	create_graph(graphi->graph, find_nb_vertices(infos->rooms));
	gen_edges(graphi, infos->tunnels);
	remp_rooms_info(graphi->graph, infos->rooms);
	return (graphi);
}