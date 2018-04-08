/*
** EPITECH PROJECT, 2017
** list.h
** File description:
** Header file for linked lists
*/
#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct	s_node
{
	int		path;
	void		*data;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	**graph;
	struct s_node	*shortest;
	bool		visited;
}		t_node;

int	add_edge(t_node *, int, int);
void	free_list(t_node *list, void (*ptr)(void *data));
void	display_reverse(t_node *head, void (*ptr)(void *data));
void	display_list(t_node *head, void (*ptr)(void *data));
void	my_sort_list(t_node *list, int (*ptr)(void *data, void *data_2));
void	insert_end(t_node **head, void *data);

#endif /* !LIST_H_ */