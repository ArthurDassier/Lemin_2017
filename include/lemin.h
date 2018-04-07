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

// Generating graphs
void	create_graph(t_node **, int);
int	add_edge(t_node *, int, int);
//t_graph *gen_graph(t_infos *);
t_node	*get_graph_index(t_node *, int);
int	get_graph_len(t_node **node);

// Algorithm
void	pathfinding(t_node *);
void	repeat(t_node *node);


// Display
void	print_list(void *data);
void	display_graph(void *);
void print_graph(t_node *node);

// Error handling
int	recup_anthill(t_infos *, int);
//void fuel_tunnel(char **, t_infos *, int);
// int found_tunnels(char *);
// void fuel_room_name(t_infos *, int);
//t_graph *gen_graph(t_infos *);
int fuel_tnl(char **, t_infos *, int);
int found_tunnels(char *);
//int fuel_room_name(t_infos *, int);
int analyse_command(char *, int *);
int check_params(char **);
int end_n_start(t_room **);
int check_for_double_names(char **names);

#endif /* !LEMIN_H_ */
