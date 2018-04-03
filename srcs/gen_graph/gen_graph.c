/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** gen_graph
*/

#include "lemin.h"

// static int find_nb_vertices(char **names)
// {
// 	int	i = 0;

// 	while (names[i])
// 		++i;
// 	return (i);
// }

// static void remp_rooms_info(t_graph *graph, t_room **room)
// {
// 	t_room		*tmp_room = NULL;
// 	t_adj_node	*tmp = NULL;
// 	int		i = 0;
// 	int		nb = 0;

// 	while (room[i]) {
// 		nb = room[i]->nb_room;
// 		tmp = graph->array[nb].head;
// 		graph->array[nb].head->data = malloc(sizeof(t_room));
// 		tmp_room = (t_room *)tmp->data;
// 		tmp_room->ant = room[i]->ant;
// 		tmp_room->x = room[i]->x;
// 		tmp_room->y = room[i]->y;
// 		tmp_room->type = room[i]->type;
// 		tmp_room->nb_room = room[i]->nb_room;
// 		++i;
// 	}
// }

// t_graph	*gen_graph(t_infos *infos)
// {
// 	t_graph		*graph =
// 	create_graph(find_nb_vertices(infos->tunnels->names));
// 	int		i = 0;

// 	while (infos->tunnels->tunnels[i]) {
// 		add_edge(graph, infos->tunnels->tunnels[i][0],
// 		infos->tunnels->tunnels[i][1]);
// 		++i;
// 	}
// 	remp_rooms_info(graph, infos->rooms);
// 	free(infos);
// 	free(infos->tunnels);
// 	free(infos->rooms);
// 	return (graph);
// }