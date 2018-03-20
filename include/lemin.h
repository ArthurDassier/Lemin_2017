/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** lemin
*/

#ifndef LEMIN_H_
#define LEMIN_H_

#include "my.h"
#include "list.h"
#include "graph.h"

typedef struct s_room
{
	int	ant;
	int	nb_room;
	int	x;
	int	y;
	int	type;
} t_room;

typedef struct s_tunnels
{
	int	**tunnels;
	char	**names;
} t_tunnels;

t_room **recup_anthill(t_tunnels *tunnels, int nb_rm);
// Parser
t_room **recup_anthill(t_tunnels *, int);

// Algorithm
t_graph *gen_graph(t_room **);

#endif /* !LEMIN_H_ */
