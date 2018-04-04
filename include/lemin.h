/*
** EPITECH PROJECT, 2018
** CPE_lemin_2017
** File description:
** lemin
*/

#ifndef LEMIN_H_
#define LEMIN_H_
#include "define.h"
#include "my.h"
#include "list.h"
#include "graph.h"

typedef struct	s_room
{
	int	nb_room;
	char	*name_room;
	int	x;
	int	y;
	int	type;
	int	ant_total;
	bool	ant;
}		t_room;

typedef struct s_infos
{
	t_node		*rooms;
	t_node		*tunnels;
} t_infos;

void	create_graph(t_node **node, int vertices);
void	print_list(void *data);
char	**recup_anthill(t_infos *, char **);
void	display_graph(void *);
void fuel_tunnel(char **, t_infos *, int);
int found_tunnels(char *);
char **fuel_room_name(t_infos *);
void print_graph(t_node *node);
int add_edge(t_node *, int, int);
t_node *gen_graph(t_infos *);
int fuel_tnl(char **, t_infos *);
int analyse_command(char *, int *);
int check_params(char **);
int end_n_start(t_node *);
int check_for_double_names(char **);

#endif /* !LEMIN_H_ */
