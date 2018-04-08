/*
** EPITECH PROJECT, 2018
** end_to_start.c
** File description:
** Arthur
*/

#include "lemin.h"

static int *add_path(int *tmp_tunnel, int *path)
{
	int	i = 0;
	int	end_line = 0;

	while (path[end_line] != -1)
		++end_line;
	while (path[i] != -1) {
		if (tmp_tunnel[0] == path[i]) {
			path[end_line] =  tmp_tunnel[1];
			path[end_line + 1] = -1;
			return (path);
		}
		if (tmp_tunnel[1] == path[i]) {
			path[end_line] =  tmp_tunnel[0];
			path[end_line + 1] = -1;
			return (path);
		}
		++i;
	}
	return (path);
}

static int check_path(int *path, int begin, int finnish)
{
	int	i = 0;
	int	start = 0;
	int	end = 0;

	while (path[i] != -1) {
		if (path[i] == begin)
			++start;
		if (path[i] == finnish)
			++end;
		++i;
	}
	if (start > 0 && end > 0)
		return (SUCCESS);
	return (FAILURE);
}

static int build_path(t_infos *infos, int *path)
{
	t_node	*tmp_node = infos->tunnels;
	int	*tmp_tunnel = NULL;

	do {
		tmp_tunnel = (int *)tmp_node->data;
		path = add_path(tmp_tunnel, path);
		if (check_path(path, infos->index_start,
		infos->index_end) == SUCCESS) {
			return (SUCCESS);
		}
			tmp_node = tmp_node->next;
	} while (tmp_node != infos->tunnels);
	return (FAILURE);
}

int end_to_start(t_infos *infos, char **index)
{
	int	*path;
	int	i = 0;

	while (index[i] != NULL)
		++i;
	path = malloc(sizeof(int) * (i * i));
	if (path == NULL)
		return (FAILURE);
	path[0] = infos->index_start;
	path[1] = -1;
	while (i != 0) {
		if (build_path(infos, path) == SUCCESS) {
			free(path);
			return (SUCCESS);
		}
		--i;
	}
	free(path);
	return (FAILURE);
}
