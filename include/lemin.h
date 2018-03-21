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

typedef struct s_infos
{
	t_room		**rooms;
	t_tunnels	*tunnels;
} t_infos;

int recup_anthill(t_infos *, int);
t_graph *gen_graph(t_infos *);
void fuel_tnl(char **, t_infos *, int);
int found_tunnels(char *);
void fuel_room_name(t_infos *, int);
int analyse_command(char *line, int *type_next_room);

#endif /* !LEMIN_H_ */
