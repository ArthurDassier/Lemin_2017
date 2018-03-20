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

t_graph *gen_graph(t_room **);

#endif /* !LEMIN_H_ */
