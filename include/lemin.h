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
	char	*name;
	int	x;
	int	y;
	char	**tunnels;
	int	type;
} t_room;

#endif /* !LEMIN_H_ */
