/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** gen_graph
*/

#include "lemin.h"

static int nb_vertices(char **tab)
{
	int	i = 0;

	while (tab[i])
		++i;
	return (i);
}

static void gen_graph(t_node **node, t_infos *infos, char **tab)
{
	t_node	*head_tunnels = infos->tunnels;
	int	*tmp = NULL;

	create_graph(node, infos, nb_vertices(tab));
	do {
		tmp = (int *)infos->tunnels->data;
		add_edge(*node, (tmp[0] + 1), (tmp[1] + 1));
		add_edge(*node, (tmp[1] + 1), (tmp[0] + 1));
		infos->tunnels = infos->tunnels->next;
	} while (infos->tunnels != head_tunnels);
}

void init_graph(t_node **node, t_infos *infos, char **tab)
{
	gen_graph(node, infos, tab);
}