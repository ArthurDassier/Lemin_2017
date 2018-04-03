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
	char	*name_room;
	int	x;
	int	y;
	int	type;
} t_room;

typedef struct s_tunnels
{
	int	**tab_tunnels;
	char	**names;
} t_tunnels;

typedef struct s_infos
{
	t_room		**rooms;
	t_tunnels	*tunnels;
} t_infos;

int recup_anthill(t_infos *, int);
t_graph *gen_graph(t_infos *);
int fuel_tnl(char **, t_infos *, int);
int found_tunnels(char *);
int fuel_room_name(t_infos *, int);
int analyse_command(char *, int *);
int check_params(char **);
int end_n_start(t_room **);
int check_for_double_names(char **names);

#endif /* !LEMIN_H_ */
