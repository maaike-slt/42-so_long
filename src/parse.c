/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:30:43 by msloot            #+#    #+#             */
/*   Updated: 2024/03/12 18:17:45 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

/*
// put the length of the first read line into env->map.w
// check that all read line have the same width as the first read one
// and put the number of line read into env->map.h
*/

static size_t	load_map(t_env *env, const char *path)
{
	int		fd;
	char	*line;
	size_t	n_line;

	fd = open(path, O_RDONLY);
	printf("fd:\t%d\n\n", fd);
	if (fd < 0)
	{
		ft_puterr("could not open the file ");
		ft_putstr_fd(Y_B_MAG, STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(Y_RESET, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		return (0);
	}
	n_line = 0;
	line = get_next_line(fd);
	env->map.w = ft_strlen(&line[n_line]);
	while (line != NULL)
	{
		if (env->map.ptr)
			env->map.ptr[n_line] = line;
		n_line++;
		printf("%s", line);
		if (ft_strlen(line) != env->map.w)
		{
			ft_puterr("the given map does not have a rectangular shape\n");
			return (-1);
		}
		if (!env->map.ptr)
			free(line);
		line = get_next_line(fd);
	}
	close(fd);
	env->map.h = n_line;
	printf("\n%zu\n", env->map.w - 1);
	printf("%zu\n", env->map.h);
	return (n_line);
}

bool	parse(t_env *env, const char *path)
{
	size_t	size;
	size_t	n_line;

	size = ft_strlen(path);
	if (size < 4 || ft_strcmp(&path[size - 4], ".ber") != 0)
	{
		ft_puterr("not the right filetype, a .ber file is needed\n");
		return (false);
	}
	n_line = load_map(env, path);
	if (!n_line)
		return (false);
	env->map.ptr = (t_cell **)malloc(sizeof(t_cell *) * (n_line + 1));
	if (!env->map.ptr)
		return (false);
	return (load_map(env, path) > 0);
}
