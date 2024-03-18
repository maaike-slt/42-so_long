/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:30:43 by msloot            #+#    #+#             */
/*   Updated: 2024/03/18 17:01:31 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	empty_line(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (!len || line[0] == '\n')
		return (ft_puterr("found an empty line while reading the map"), 0);
	if (line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
		len--;
	}
	return (len);
}

static size_t	read_map(t_env *env, int fd)
{
	char	*line;
	size_t	len;

	env->map.h = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = empty_line(line);
		if (!len)
			return (0);
		if (!env->map.ptr)
		{
			if (env->map.h == 0)
				env->map.w = len;
			else if (env->map.w != len)
				return (\
ft_puterr("the given map does not have a rectangular shape\n"), 0);
			free(line);
		}
		else
			env->map.ptr[env->map.h] = line;
		env->map.h++;
		line = get_next_line(fd);
	}
	return (env->map.h);
}

static size_t	load_map(t_env *env, const char *path)
{
	int		fd;
	size_t	n_line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_puterr("could not open the file ");
		ft_putstr_fd(Y_B_MAG, STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(Y_RESET, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		return (0);
	}
	n_line = read_map(env, fd);
	close(fd);
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
