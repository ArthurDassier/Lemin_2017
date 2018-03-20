/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** gen_graph
*/

#include "lemin.h"

static int find_nb_vertices(char **names)
{
	int	i = 0;

	while (names[i])
		++i;
	return (i);
}

static void remp_rooms_info(t_graph *graph, t_room **room)
{
	t_room		*tmp_room;
	t_adj_node	*tmp;
	int		i = 0;
	int		nb = 0;

	while (room[i]) {
		nb = room[i]->nb_room;
		tmp = graph->array[nb].head;
		tmp_room = (t_room *)tmp->data;
		tmp_room->ant = room[i]->ant;
		tmp_room->x = room[i]->x;
		tmp_room->y = room[i]->y;
		tmp_room->type = room[i]->type;
		tmp_room->nb_room = room[i]->nb_room;
		++i;
	}
}

t_graph	*gen_graph(t_room **info)
{
	t_graph	*graph = create_graph(3);
	int	i = 0;

	int tunnels[3][2] = {
		{0, 1},
		{2, 3},
		{2, 1}
	};
	while (tunnels[i]) {
		add_edge(graph, tunnels[i][0], tunnels[i][1]);
		++i;
	}
	remp_rooms_info(graph, info);
	return (graph);
}