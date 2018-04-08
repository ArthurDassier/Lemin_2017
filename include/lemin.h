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

typedef	struct	s_ant {
	t_node	*room;
	int	ant_nb;
	bool	moved;
}		t_ant;

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

typedef struct	s_infos
{
	t_node	*rooms;
	t_node	*tunnels;
	t_node	*t_display;
	int	index_start;
	int	index_end;
}		t_infos;

// Generating graphs
void	create_graph(t_node **, t_infos *, int);
int	add_edge(t_node *, int, int);
t_node	*get_graph_index(t_node *, int);
int	get_graph_len(t_node **);

// Algorithm
void	djikstra(t_node **);
t_node	*get_room(t_node *, int);
void	send_ants(t_node **);
void	update_ants(t_node *, t_node *, t_node **);
t_node	*check_ants(t_node *);
int	get_total_end(t_node *);
int	get_total(t_node *);

// Display
void	print_list(void *);
void	display_graph(void *);
void	print_graph(t_node *);
void	display_infos(t_infos *);
void	display_moves(int id, char *name);

// Clean up
t_node	*find_trash_node(t_node *);
void	delete_node(t_node **, int);
void	delete_trash_node(t_node **, t_node *);
void	clean_up(t_node **);

// Error handling
int found_l_problem(char *);
void init_inf(t_infos **);
char	**recup_anthill(t_infos **, char **);
void	display_graph(void *);
void	fuel_tunnel(char **, t_infos *, int);
int	found_tunnels(char *);
char	**fuel_room_name(t_infos *);
void	print_graph(t_node *node);
int	add_edge(t_node *, int, int);
void	init_graph(t_node **, t_infos *, char **);
int	fuel_tnl(char **, t_infos *);
int	analyse_command(char *, int *);
int	check_params(char **);
int	end_n_start(t_node *);
int	check_for_double_names(char **);
int	look_for_coordinates(t_node *);
int	end_to_start(t_infos *, char **);


#endif /* !LEMIN_H_ */